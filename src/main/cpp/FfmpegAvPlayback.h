#ifndef FFMPEGAVPLAYBACK_H_
#define FFMPEGAVPLAYBACK_H_

#include "PlayerState.h"
#include "VideoState.h"

class FfmpegAvPlayback {
public:
  FfmpegAvPlayback();
  int OpenVideo(const char *filename, AVInputFormat *p_input_format,
                int audio_buffer_size);
  virtual void
  SetUpdatePlayerStateCallbackFunction(PlayerState::State state,
                                       const std::function<void()> &func);

  virtual void Play();
  virtual void Stop();
  virtual void Pause();

  inline virtual void Seek(double dSeekTime) {

    double pos = GetTime();

    if (isnan(pos)) {
      pos = (double)GetSeekTime() / (double)AV_TIME_BASE;
    }

    if (GetStartTime() != AV_NOPTS_VALUE && dSeekTime <= GetStartTime()) {
      dSeekTime = GetStartTime();
    } else if (GetDuration() != AV_NOPTS_VALUE && dSeekTime >= GetDuration()) {
      dSeekTime = GetDuration();
    }

    dSeekTime -= GetFrameRate() > 0 ? (1.0 / GetFrameRate()) : 0;

    double incr = dSeekTime - pos;

    p_video_state_->Seek((int64_t)(dSeekTime * AV_TIME_BASE),
                         (int64_t)(incr * AV_TIME_BASE));
  }

  inline virtual double GetDuration() const {
    return p_video_state_->GetDuration();
  }

  inline virtual double GetTime() const { return p_video_state_->GetTime(); }

  inline virtual double GetFrameRate() const {
    return p_video_state_->GetFrameRate();
  }

  // Set the playback speed
  virtual int SetSpeed(double speed);

  // Get the playback speed
  inline virtual double GetSpeed() const { return p_video_state_->GetSpeed(); }

  inline int64_t GetStartTime() const {
    AVFormatContext *p_format_context = nullptr;
    p_video_state_->GetFormatContext(&p_format_context);
    return p_format_context->start_time;
  }

  inline int64_t GetSeekTime() const { return p_video_state_->GetSeekTime(); }

  inline void StepToNextFrame() {
    // if the stream is paused/stopped unpause it, then step
    if (IsPaused() || IsStopped() || IsReady()) {
      // Mute player, keep the same statebecause the display loop will stop the
      // and keep the same state
      SetPlaying(false, true);
    }

    p_video_state_->SetStepping(true);
  }

  inline void StepToPreviousFrame() {

    if (IsPlaying()) {
      SetPaused(true, false);
    }

    double pos = GetTime();
    if (!isnan(pos)) {
      double dSeekTime = pos - (1.0 / GetFrameRate());

      if (GetStartTime() != AV_NOPTS_VALUE && dSeekTime <= GetStartTime()) {
        dSeekTime = GetStartTime();
      }

      double incr = dSeekTime - pos;
      p_video_state_->Seek((int64_t)(dSeekTime * AV_TIME_BASE),
                           (int64_t)(incr * AV_TIME_BASE));
    }
  }

  inline void SetPlayerStateCallbackFunction(
      const std::function<bool(PlayerState::State)> &func) {
    is_player_state_callback = func;
  }

  inline void
  SetPendingPlayerStateCallbackFunction(const std::function<void()> &func) {
    set_pending_player_state_callback = func;
  }

protected:
  // The video state used for this playback
  VideoState *p_video_state_;

  int frame_width_;
  int frame_height_;

  // Force a refresh of the display
  bool force_refresh_;

  // Disable the display
  bool display_disabled_;

  // Counts the number of early frame drops
  int num_frame_drops_late_;

  std::function<bool(PlayerState::State)> is_player_state_callback;
  std::function<void()> set_pending_player_state_callback;
  std::function<void()> update_player_state_callbacks
      [PlayerState::Error]; // Error is the last in the enum item of the enum

  // Enable the showing of the status
  static bool kEnableShowStatus;

  virtual void TogglePauseAndStopStep(bool mute = false);

  inline void SetForceReferesh(bool refresh) { force_refresh_ = refresh; }
  double ComputeFrameDuration(Frame *vp, Frame *nextvp,
                              double max_frame_duration);

  /* Setter and Getters */
  inline bool IsReady() const {
    if (is_player_state_callback) {
      return is_player_state_callback(PlayerState::State::Ready) &&
             p_video_state_->IsPaused();
    }
    return p_video_state_->IsPaused();
  }

  inline bool IsPaused() const {
    if (is_player_state_callback) {
      return is_player_state_callback(PlayerState::State::Paused) &&
             p_video_state_->IsPaused();
    }
    return p_video_state_->IsPaused();
  }

  inline void SetPaused(bool update_state = true, bool mute = false) {
    if (!IsStopped()) {
      TogglePauseAndStopStep();
    }
    if (update_state) {
      if (update_player_state_callbacks[PlayerState::State::Paused]) {
        update_player_state_callbacks[PlayerState::State::Paused]();
      }
    }
  }

  inline bool IsStopped() const {
    if (is_player_state_callback) {
      return is_player_state_callback(PlayerState::State::Stopped) &&
             p_video_state_->IsPaused();
    }
    return p_video_state_->IsPaused();
  }

  inline void SetStopped(bool update_state = true, bool mute = false) {
    if (!IsPaused()) {
      TogglePauseAndStopStep(mute);
    }
    SetSpeed(1);
    if (update_state) {
      if (update_player_state_callbacks[PlayerState::State::Stopped]) {
        update_player_state_callbacks[PlayerState::State::Stopped]();
      }
    }
  }

  inline bool IsPlaying() const {
    if (is_player_state_callback) {
      return is_player_state_callback(PlayerState::State::Playing) &&
             !p_video_state_->IsPaused();
    }
    return !p_video_state_->IsPaused();
  }

  inline void SetPlaying(bool update_state = true, bool mute = false) {
    TogglePauseAndStopStep(mute);
    if (update_state) {
      if (update_player_state_callbacks[PlayerState::State::Playing]) {
        update_player_state_callbacks[PlayerState::State::Playing]();
      }
    }
  }
};

#endif // FFMPEGAVPLAYBACK_H_
