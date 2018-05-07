/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_datavyu_plugins_ffmpegplayer_MoviePlayer0 */

#ifndef _Included_org_datavyu_plugins_ffmpegplayer_MoviePlayer0
#define _Included_org_datavyu_plugins_ffmpegplayer_MoviePlayer0
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    open0
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljavax/sound/sampled/AudioFormat;)[I
 */
JNIEXPORT jintArray JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_open0
  (JNIEnv *, jclass, jstring, jstring, jobject);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    hasVideoStream0
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_hasVideoStream0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    hasAudioStream0
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_hasAudioStream0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    play0
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_play0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    stop0
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_stop0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    pause0
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_pause0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    close0
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_close0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getImageBuffer0
 * Signature: (I)Ljava/nio/ByteBuffer;
 */
JNIEXPORT jobject JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getImageBuffer0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    loadNextImageFrame0
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_loadNextImageFrame0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getWidth0
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getWidth0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getHeight0
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getHeight0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getNumberOfColorChannels0
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getNumberOfColorChannels0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getStartTime0
 * Signature: (I)D
 */
JNIEXPORT jdouble JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getStartTime0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getEndTime0
 * Signature: (I)D
 */
JNIEXPORT jdouble JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getEndTime0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getDuration0
 * Signature: (I)D
 */
JNIEXPORT jdouble JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getDuration0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getCurrentTime0
 * Signature: (I)D
 */
JNIEXPORT jdouble JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getCurrentTime0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    seek0
 * Signature: (ID)V
 */
JNIEXPORT void JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_seek0
  (JNIEnv *, jclass, jint, jdouble);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    setSpeed0
 * Signature: (IF)V
 */
JNIEXPORT void JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_setSpeed0
  (JNIEnv *, jclass, jint, jfloat);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getAudioBuffer0
 * Signature: (II)Ljava/nio/ByteBuffer;
 */
JNIEXPORT jobject JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getAudioBuffer0
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    loadNextAudioData0
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_loadNextAudioData0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    setAudioSyncDelay0
 * Signature: (IJ)V
 */
JNIEXPORT void JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_setAudioSyncDelay0
  (JNIEnv *, jobject, jint, jlong);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getCodecName0
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getCodecName0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getSampleRate0
 * Signature: (I)F
 */
JNIEXPORT jfloat JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getSampleRate0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getSampleSizeInBits0
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getSampleSizeInBits0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getNumberOfSoundChannels0
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getNumberOfSoundChannels0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getFrameSize0
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getFrameSize0
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_datavyu_plugins_ffmpegplayer_MoviePlayer0
 * Method:    getFrameRate0
 * Signature: (I)F
 */
JNIEXPORT jfloat JNICALL Java_org_datavyu_plugins_ffmpegplayer_MoviePlayer0_getFrameRate0
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif
#endif
