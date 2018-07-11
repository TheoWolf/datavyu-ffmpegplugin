#ifndef _FFMPEG_AV_PLAYBACK_PIPELINE_H_
#define _FFMPEG_AV_PLAYBACK_PIPELINE_H_

#include "PipelineOptions.h"
#include "Pipeline.h"
#include "SDLPlayData.h"

/**
* class FfmpegAVPlaybackPipeline
*
* Class representing a Ffmpeg audio-video pipeline.
*
* Note, currently this pipeline uses SDL to play audio/image
*/
class FfmpegAVPlaybackPipeline : public CPipeline
{
public:
	virtual uint32_t    Init();
	virtual void        Dispose();
	FfmpegAVPlaybackPipeline(CPipelineOptions* pOptions);
	virtual ~FfmpegAVPlaybackPipeline();

private:
	virtual uint32_t        Play();
	virtual uint32_t        Stop();
	virtual uint32_t        Pause();
	virtual uint32_t        Finish();

	virtual uint32_t        Seek(double dSeekTime);

	virtual uint32_t        GetDuration(double* pdDuration);
	virtual uint32_t        GetStreamTime(double* pdStreamTime);

	virtual uint32_t        SetRate(float fRate);
	virtual uint32_t        GetRate(float* pfRate);

	virtual uint32_t        SetVolume(float fVolume);
	virtual uint32_t        GetVolume(float* pfVolume);

	virtual uint32_t        SetBalance(float fBalance);
	virtual uint32_t        GetBalance(float* pfBalance);

	virtual uint32_t        SetAudioSyncDelay(long lMillis);
	virtual uint32_t        GetAudioSyncDelay(long* plMillis);

	void UpdatePlayerState(PlayerState newState);
	void SetPlayerState(PlayerState newState, bool bSilent);

	SDLPlayData* pPlayer;
	std::mutex stateLock;
};

#endif  //_FFMPEG_AV_PLAYBACK_PIPELINE_H_
