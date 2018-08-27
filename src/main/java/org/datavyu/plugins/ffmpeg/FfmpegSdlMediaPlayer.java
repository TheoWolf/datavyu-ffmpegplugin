package org.datavyu.plugins.ffmpeg;

import java.io.File;

/**
 * Uses the SDL framework to playback the images and sound natively
 *
 * This class only controls the the video playback, e.g. play, stop, pause, ...
 *
 * It also provides volume control through the native SDL audio playback
 */
public final class FfmpegSdlMediaPlayer extends FfmpegMediaPlayer {

    static {
        System.loadLibrary("FfmpegSdlMediaPlayer");
    }

    public FfmpegSdlMediaPlayer(File sourceFile) {
        super(sourceFile);
    }

    @Override
    public void init() {
        initNative(); // start the event queue, make sure to register all state/error listeners before
        long[] newNativeMediaRef = new long[1];
        String filename;

        if (protocol.equals("file"))
            filename = sourcePath;
        else
            filename = sourceURI.getPath();

        int rc = ffmpegInitPlayer(newNativeMediaRef, filename);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }

        nativeMediaRef = newNativeMediaRef[0];
    }

    @Override
    protected long playerGetAudioSyncDelay() throws MediaException {
        long[] audioSyncDelay = new long[1];
        int rc = ffmpegGetAudioSyncDelay(getNativeMediaRef(), audioSyncDelay);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
        return audioSyncDelay[0];
    }

    @Override
    protected void playerSetAudioSyncDelay(long delay) throws MediaException {
        int rc = ffmpegSetAudioSyncDelay(getNativeMediaRef(), delay);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected void playerPlay() throws MediaException {
        int rc = ffmpegPlay(getNativeMediaRef());
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected void playerStop() throws MediaException {
        int rc = ffmpegStop(getNativeMediaRef());
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected void playerPause() throws MediaException {
        int rc = ffmpegPause(getNativeMediaRef());
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected void playerStepForward() throws MediaException {
        int rc = ffmpegStepForward(getNativeMediaRef());
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected void playerFinish() throws MediaException {
        int rc = ffmpegFinish(getNativeMediaRef());
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected float playerGetRate() throws MediaException {
        float[] rate = new float[1];
        int rc = ffmpegGetRate(getNativeMediaRef(), rate);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
        return rate[0];
    }

    @Override
    protected void playerSetRate(float rate) throws MediaException {
        int rc = ffmpegSetRate(getNativeMediaRef(), rate);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected double playerGetPresentationTime() throws MediaException {
        double[] presentationTime = new double[1];
        int rc = ffmpegGetPresentationTime(getNativeMediaRef(), presentationTime);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
        return presentationTime[0];
    }

    @Override
    protected double playerGetFps() throws MediaException {
        double[] framePerSecond = new double[1];
        int rc = ffmpegGetFps(getNativeMediaRef(), framePerSecond);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
        return framePerSecond[0];
    }


    @Override
    protected float playerGetVolume() throws MediaException {
        synchronized(this) {
            if (muteEnabled)
                return mutedVolume;
        }
        float[] volume = new float[1];
        int rc = ffmpegGetVolume(getNativeMediaRef(), volume);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
        return volume[0];
    }

    @Override
    protected synchronized void playerSetVolume(float volume) throws MediaException {
        if (!muteEnabled) {
            int rc = ffmpegSetVolume(getNativeMediaRef(), volume);

            if (0 != rc) {
                throwMediaErrorException(rc, null);
            } else {
                 mutedVolume = volume;
            }
        } else {
            mutedVolume = volume;
        }
    }

    @Override
    protected float playerGetBalance() throws MediaException {
        float[] balance = new float[1];
        int rc = ffmpegGetBalance(getNativeMediaRef(), balance);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
        return balance[0];
    }

    @Override
    protected void playerSetBalance(float balance) throws MediaException {
        int rc = ffmpegSetBalance(getNativeMediaRef(), balance);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected double playerGetDuration() throws MediaException {
        double[] duration = new double[1];
        int rc = ffmpegGetDuration(getNativeMediaRef(), duration);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
        if (duration[0] == -1.0) {
            return Double.POSITIVE_INFINITY;
        } else {
            return duration[0];
        }
    }

    @Override
    protected void playerSeek(double streamTime) throws MediaException {
        int rc = ffmpegSeek(getNativeMediaRef(), streamTime);
        if (0 != rc) {
            throwMediaErrorException(rc, null);
        }
    }

    @Override
    protected void playerDispose() {
        ffmpegDisposePlayer(getNativeMediaRef());
    }

    // Native methods
    protected native int ffmpegInitPlayer(long[] newNativeMedia,
                                          String sourcePath);

    protected native int ffmpegDisposePlayer(long refNativeMedia);

    protected native int ffmpegGetAudioSyncDelay(long refNativeMedia, long[] syncDelay);
    protected native int ffmpegSetAudioSyncDelay(long refNativeMedia, long delay);
    protected native int ffmpegPlay(long refNativeMedia);
    protected native int ffmpegPause(long refNativeMedia);
    protected native int ffmpegStop(long refNativeMedia);
    protected native int ffmpegStepForward(long refNativeMedia);
    protected native int ffmpegFinish(long refNativeMedia);
    protected native int ffmpegGetRate(long refNativeMedia, float[] rate);
    protected native int ffmpegSetRate(long refNativeMedia, float rate);
    protected native int ffmpegGetPresentationTime(long refNativeMedia, double[] time);
    protected native int ffmpegGetFps(long refNativeMedia, double[] fps);
    protected native int ffmpegGetBalance(long refNativeMedia, float[] balance);
    protected native int ffmpegSetBalance(long refNativeMedia, float balance);
    protected native int ffmpegGetDuration(long refNativeMedia, double[] duration);
    protected native int ffmpegSeek(long refNativeMedia, double streamTime);
    protected native int ffmpegGetVolume(long refNativeMedia, float[] volume);
    protected native int ffmpegSetVolume(long refNativeMedia, float volume);
}