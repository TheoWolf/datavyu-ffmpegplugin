#ifndef FFMPEGSDLAVPLAYBACK_H_
#define FFMPEGSDLAVPLAYBACK_H_

#include <atomic>
#include "VideoState.h"
#include "FfmpegAVPlayback.h"

extern "C" {
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_thread.h>
}
/* Minimum SDL audio buffer size, in samples. */
#define SDL_AUDIO_MIN_BUFFER_SIZE 512

/* Calculate actual buffer size keeping in mind not cause too frequent audio callbacks */
#define SDL_AUDIO_MAX_CALLBACKS_PER_SEC 30

/* AV sync correction is done if above the maximum AV sync threshold */
#define AV_SYNC_THRESHOLD_MAX 0.1

/* Step size for volume control in dB */
#define SDL_VOLUME_STEP (0.75)

/* polls for possible required screen refresh at least this often, should be less than 1/fps */
#define REFRESH_RATE 0.01

#define USE_ONEPASS_SUBTITLE_RENDER 1

#define CURSOR_HIDE_DELAY 1000000

/* NOTE: the size must be big enough to compensate the hardware audio buffersize size */
/* TODO: We assume that a decoded and resampled frame fits into this buffer */
#define SAMPLE_ARRAY_SIZE (8 * 65536)

#define FF_QUIT_EVENT    (SDL_USEREVENT + 2)

const char program_name[] = "Datavyu-ffmpeg-plugin";

static const char *window_title;
static int borderless;
static int64_t cursor_last_shown;
static int cursor_hidden = 0;
static int exit_on_keydown;
static int exit_on_mousedown;

static int default_width = 640;
static int default_height = 480;
static unsigned sws_flags = SWS_BICUBIC;

static int16_t sample_array[SAMPLE_ARRAY_SIZE];
static int sample_array_index;

static const struct TextureFormatEntry {
	enum AVPixelFormat format;
	int texture_fmt;
} sdl_texture_format_map[] = {
	{ AV_PIX_FMT_RGB8,           SDL_PIXELFORMAT_RGB332 },
	{ AV_PIX_FMT_RGB444,         SDL_PIXELFORMAT_RGB444 },
	{ AV_PIX_FMT_RGB555,         SDL_PIXELFORMAT_RGB555 },
	{ AV_PIX_FMT_BGR555,         SDL_PIXELFORMAT_BGR555 },
	{ AV_PIX_FMT_RGB565,         SDL_PIXELFORMAT_RGB565 },
	{ AV_PIX_FMT_BGR565,         SDL_PIXELFORMAT_BGR565 },
	{ AV_PIX_FMT_RGB24,          SDL_PIXELFORMAT_RGB24 },
	{ AV_PIX_FMT_BGR24,          SDL_PIXELFORMAT_BGR24 },
	{ AV_PIX_FMT_0RGB32,         SDL_PIXELFORMAT_RGB888 },
	{ AV_PIX_FMT_0BGR32,         SDL_PIXELFORMAT_BGR888 },
	{ AV_PIX_FMT_NE(RGB0, 0BGR), SDL_PIXELFORMAT_RGBX8888 },
	{ AV_PIX_FMT_NE(BGR0, 0RGB), SDL_PIXELFORMAT_BGRX8888 },
	{ AV_PIX_FMT_RGB32,          SDL_PIXELFORMAT_ARGB8888 },
	{ AV_PIX_FMT_RGB32_1,        SDL_PIXELFORMAT_RGBA8888 },
	{ AV_PIX_FMT_BGR32,          SDL_PIXELFORMAT_ABGR8888 },
	{ AV_PIX_FMT_BGR32_1,        SDL_PIXELFORMAT_BGRA8888 },
	{ AV_PIX_FMT_YUV420P,        SDL_PIXELFORMAT_IYUV },
	{ AV_PIX_FMT_YUYV422,        SDL_PIXELFORMAT_YUY2 },
	{ AV_PIX_FMT_UYVY422,        SDL_PIXELFORMAT_UYVY },
	{ AV_PIX_FMT_NONE,           SDL_PIXELFORMAT_UNKNOWN },
};

static SDL_RendererInfo renderer_info = { 0 };


class FfmpegSdlAvPlayback : public FfmpegAvPlayback {

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_AudioDeviceID audio_dev = 0;
	int ytop, xleft;
	int xpos;

	struct SwsContext *img_convert_ctx;
	struct SwsContext *sub_convert_ctx;

	SDL_Texture *vis_texture;
	SDL_Texture *sub_texture;
	SDL_Texture *vid_texture;

	int last_i_start;

	int screen_width;
	int screen_height;
	int is_full_screen;

	int audio_volume;

	inline int compute_mod(int a, int b);

	inline void fill_rectangle(int x, int y, int w, int h);

	static void calculate_display_rect(SDL_Rect *rect,
		int scr_xleft, int scr_ytop, int scr_width, int scr_height,
		int pic_width, int pic_height, AVRational pic_sar);

	std::atomic<bool> stopped = false;
	std::thread* display_tid = nullptr;

	void InitSdl(); // This is private because it has to be called on the same thread as the looping
	int video_open(const char* filename);
	void closeAudioDevice();
	void video_image_display();
	void stop_display_loop();
public:
	FfmpegSdlAvPlayback(int startup_volume = SDL_MIX_MAXVOLUME);
	~FfmpegSdlAvPlayback();

	int Init(const char *filename, AVInputFormat *iformat);

	VideoState* get_VideoState();

	int audio_open(int64_t wanted_channel_layout, int wanted_nb_channels, int wanted_sample_rate,
		struct AudioParams *audio_hw_params);

	static void set_default_window_size(int width, int height, AVRational sar);

	void pauseAudioDevice();

	/* copy samples for viewing in editor window */
	static void update_sample_display(short *samples, int samples_size);

	void toggle_full_screen();

	int upload_texture(SDL_Texture **tex, AVFrame *frame, struct SwsContext **img_convert_ctx);

	static void get_sdl_pix_fmt_and_blendmode(int format, Uint32 *sdl_pix_fmt, SDL_BlendMode *sdl_blendmode);

	int realloc_texture(SDL_Texture **texture, Uint32 new_format, int new_width, 
						int new_height, SDL_BlendMode blendmode, int init_texture);

	/* display the current picture, if any */
	void video_display();

	int get_audio_volume() const;

	void update_volume(int sign, double step);

	// Function Called from the event loop
	void refresh_loop_wait_event(SDL_Event *event);

	/* called to display each frame */
	void video_refresh(double *remaining_time);

	void destroy();

	void init_and_event_loop();

	int init_and_start_display_loop();
};

static void sdl_audio_callback_bridge(void* vs, Uint8 *stream, int len) {
	FfmpegSdlAvPlayback* pFfmpegSdlAvPlayback = static_cast<FfmpegSdlAvPlayback*>(vs);
	VideoState* pVideoState = pFfmpegSdlAvPlayback->get_VideoState();
	pVideoState->audio_callback(stream, len);

	// Note, the mixer can work inplace using the same stream as src and dest, see source code here
	// https://github.com/davidsiaw/SDL2/blob/c315c99d46f89ef8dbb1b4eeab0fe38ea8a8b6c5/src/audio/SDL_mixer.c
	if (!pVideoState->get_muted() && stream)
		SDL_MixAudioFormat(stream, stream, AUDIO_S16SYS, len, pFfmpegSdlAvPlayback->get_audio_volume());
}

#endif FFMPEGSDLAVPLAYBACK_H_
