/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer */

#ifndef _Included_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
#define _Included_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
#ifdef __cplusplus
extern "C" {
#endif
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerUnknown
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerUnknown 100L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerReady
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerReady 101L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerPlaying
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerPlaying 102L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerPaused
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerPaused 103L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerStopped
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerStopped 104L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerStalled
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerStalled 105L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerFinished
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerFinished 106L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerError
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_eventPlayerError 107L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_SEEK_ACCURATE_FLAG
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_SEEK_ACCURATE_FLAG 1L
#undef org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_SEEK_FAST_FLAG
#define org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_SEEK_FAST_FLAG 16L
/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegInitPlayer
 * Signature: ([JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegInitPlayer
  (JNIEnv *, jobject, jlongArray, jstring);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegDisposePlayer
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegDisposePlayer
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetAudioSyncDelay
 * Signature: (J[J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetAudioSyncDelay
  (JNIEnv *, jobject, jlong, jlongArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegSetAudioSyncDelay
 * Signature: (JJ)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegSetAudioSyncDelay
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegPlay
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegPlay
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegPause
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegPause
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegStop
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegStop
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegStepForward
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegStepForward
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegStepBackward
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegStepBackward
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegFinish
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegFinish
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetRate
 * Signature: (J[F)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetRate
  (JNIEnv *, jobject, jlong, jfloatArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegSetRate
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegSetRate
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetPresentationTime
 * Signature: (J[D)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetPresentationTime
  (JNIEnv *, jobject, jlong, jdoubleArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetFps
 * Signature: (J[D)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetFps
  (JNIEnv *, jobject, jlong, jdoubleArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetBalance
 * Signature: (J[F)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetBalance
  (JNIEnv *, jobject, jlong, jfloatArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegSetBalance
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegSetBalance
  (JNIEnv *, jobject, jlong, jfloat);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetDuration
 * Signature: (J[D)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetDuration
  (JNIEnv *, jobject, jlong, jdoubleArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegSeek
 * Signature: (JDI)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegSeek
  (JNIEnv *, jobject, jlong, jdouble, jint);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegSeekToFrame
 * Signature: (JDI)I
*/
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegSeekToFrame
(JNIEnv *, jobject, jlong, jint);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetImageWidth
 * Signature: (J[I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetImageWidth
(JNIEnv *, jobject, jlong, jintArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetImageHeight
 * Signature: (J[I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetImageHeight
(JNIEnv *, jobject, jlong, jintArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegGetVolume
 * Signature: (J[F)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegGetVolume
  (JNIEnv *, jobject, jlong, jfloatArray);

/*
 * Class:     org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer
 * Method:    ffmpegSetVolume
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpeg_FfmpegSdlMediaPlayer_ffmpegSetVolume
  (JNIEnv *, jobject, jlong, jfloat);

#ifdef __cplusplus
}
#endif
#endif
