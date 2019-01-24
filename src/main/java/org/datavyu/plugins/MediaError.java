package org.datavyu.plugins;

import java.util.*;

/**
 * Media error codes that are also used in the native code to
 * communicate the error through an error number to the JVM.
 *
 * <p>The error messages are loaded from a properties
 * file. Currently, properties only exist in English.
 *
 * <p>Note, that error codes are kept as much as possible
 * compatible with those from javafx. Thus,
 * the numbering may appear a bit jumpy.
 */
public enum MediaError {
  ERROR_NONE(0x0),

  ERROR_MEDIA_BASE(0x00000100),
  ERROR_MEDIA_NULL(ERROR_MEDIA_BASE.code() + 0x0001),
  ERROR_MEDIA_CREATION(ERROR_MEDIA_BASE.code() + 0x0002),
  ERROR_MEDIA_INVALID(ERROR_MEDIA_BASE.code() + 0x0004),

  ERROR_PIPELINE_BASE(0x00000300),
  ERROR_PIPELINE_NULL(ERROR_PIPELINE_BASE.code() + 0x0001),
  ERROR_PIPELINE_CREATION(ERROR_PIPELINE_BASE.code() + 0x0002),

  ERROR_PLAYBACK_BASE(0x00000700),
  ERROR_PLAYBACK_NULL(ERROR_PLAYBACK_BASE.code() + 0x0001),

  ERROR_MPV_BASE(0x0000076C),
  ERROR_MPV_EVENT_QUEUE_FULL(ERROR_MPV_BASE.code() + 0x0001),
  ERROR_MPV_NOMEM(ERROR_MPV_BASE.code() + 0x0002),
  ERROR_MPV_UNINITIALIZED(ERROR_MPV_BASE.code() + 0x0003),
  ERROR_MPV_INVALID_PARAMETER(ERROR_MPV_BASE.code() + 0x0004),
  ERROR_MPV_OPTION_NOT_FOUND(ERROR_MPV_BASE.code() + 0x0005),
  ERROR_MPV_OPTION_FORMAT(ERROR_MPV_BASE.code() + 0x0006),
  ERROR_MPV_OPTION_ERROR(ERROR_MPV_BASE.code() + 0x0007),
  ERROR_MPV_PROPERTY_NOT_FOUND(ERROR_MPV_BASE.code() + 0x0008),
  ERROR_MPV_PROPERTY_FORMAT(ERROR_MPV_BASE.code() + 0x0009),
  ERROR_MPV_PROPERTY_UNAVAILABLE(ERROR_MPV_BASE.code() + 0x000A),
  ERROR_MPV_PROPERTY_ERROR(ERROR_MPV_BASE.code() + 0x000B),
  ERROR_MPV_COMMAND(ERROR_MPV_BASE.code() + 0x000C),
  ERROR_MPV_LOADING_FAILED(ERROR_MPV_BASE.code() + 0x000D),
  ERROR_MPV_AO_INIT_FAILED(ERROR_MPV_BASE.code() + 0x000E),
  ERROR_MPV_VO_INIT_FAILED(ERROR_MPV_BASE.code() + 0x00F),
  ERROR_MPV_NOTHING_TO_PLAY(ERROR_MPV_BASE.code() + 0x0010),
  ERROR_MPV_UNKNOWN_FORMAT(ERROR_MPV_BASE.code() + 0x0011),
  ERROR_MPV_UNSUPPORTED(ERROR_MPV_BASE.code() + 0x0012),
  ERROR_MPV_NOT_IMPLEMENTED(ERROR_MPV_BASE.code() + 0x0013),
  ERROR_MPV_GENERIC(ERROR_MPV_BASE.code() + 0x0014),

  ERROR_FFMPEG_BASE(0x00000900),
  ERROR_FFMPEG_BSF_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x0001),
  ERROR_FFMPEG_BUG(ERROR_FFMPEG_BASE.code() + 0x0002),
  ERROR_FFMPEG_BUFFER_TOO_SMALL(ERROR_FFMPEG_BASE.code() + 0x0003),
  ERROR_FFMPEG_DECODER_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x0004),
  ERROR_FFMPEG_DEMUXER_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x0005),
  ERROR_FFMPEG_ENCODER_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x0006),
  ERROR_FFMPEG_EOF(ERROR_FFMPEG_BASE.code() + 0x0007),
  ERROR_FFMPEG_EXIT(ERROR_FFMPEG_BASE.code() + 0x0008),
  ERROR_FFMPEG_EXTERNAL(ERROR_FFMPEG_BASE.code() + 0x0009),
  ERROR_FFMPEG_FILTER_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x000A),
  ERROR_FFMPEG_INVALIDDATA(ERROR_FFMPEG_BASE.code() + 0x000B),
  ERROR_FFMPEG_MUXER_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x000C),
  ERROR_FFMPEG_OPTION_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x000D),
  ERROR_FFMPEG_PATCHWELCOME(ERROR_FFMPEG_BASE.code() + 0x000E),
  ERROR_FFMPEG_PROTOCOL_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x000F),
  ERROR_FFMPEG_STREAM_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x0010),
  ERROR_FFMPEG_BUG2(ERROR_FFMPEG_BASE.code() + 0x0011),
  ERROR_FFMPEG_UNKNOWN(ERROR_FFMPEG_BASE.code() + 0x0012),
  ERROR_FFMPEG_EXPERIMENTAL(ERROR_FFMPEG_BASE.code() + 0x0013),
  ERROR_FFMPEG_INPUT_CHANGED(ERROR_FFMPEG_BASE.code() + 0x0014),
  ERROR_FFMPEG_OUTPUT_CHANGED(ERROR_FFMPEG_BASE.code() + 0x0015),
  ERROR_FFMPEG_HTTP_BAD_REQUEST(ERROR_FFMPEG_BASE.code() + 0x0016),
  ERROR_FFMPEG_HTTP_UNAUTHORIZED(ERROR_FFMPEG_BASE.code() + 0x0017),
  ERROR_FFMPEG_HTTP_FORBIDDEN(ERROR_FFMPEG_BASE.code() + 0x0018),
  ERROR_FFMPEG_HTTP_NOT_FOUND(ERROR_FFMPEG_BASE.code() + 0x0019),
  ERROR_FFMPEG_HTTP_OTHER_4XX(ERROR_FFMPEG_BASE.code() + 0x001A),
  ERROR_FFMPEG_HTTP_SERVER_ERROR(ERROR_FFMPEG_BASE.code() + 0x001B),
  ERROR_FFMPEG_AUDIO_FORMAT_NULL(ERROR_FFMPEG_BASE.code() + 0x001C),
  ERROR_FFMPEG_AUDIO_FORMAT_ENCODING_NULL(ERROR_FFMPEG_BASE.code() + 0x001D),
  ERROR_FFMPEG_AUDIO_FORMAT_ENCODING_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x001E),
  ERROR_FFMPEG_AUDIO_FORMAT_ENCODING_CLASS_NULL(ERROR_FFMPEG_BASE.code() + 0x001F),
  ERROR_FFMPEG_AUDIO_FORMAT_ENCODING_NAME_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x0020),
  ERROR_FFMPEG_AUDIO_FORMAT_ENDIAN_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x0021),
  ERROR_FFMPEG_AUDIO_FORMAT_SAMPLE_RATE_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x0022),
  ERROR_FFMPEG_AUDIO_FORMAT_SAMPLE_SIZE_IN_BITS_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x0023),
  ERROR_FFMPEG_AUDIO_FORMAT_CHANNELS_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x0024),
  ERROR_FFMPEG_AUDIO_FORMAT_FRAME_SIZE_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x0025),
  ERROR_FFMPEG_AUDIO_FORMAT_FRAME_RATE_ID_NULL(ERROR_FFMPEG_BASE.code() + 0x0026),
  ERROR_FFMPEG_COLOR_SPACE_NULL(ERROR_FFMPEG_BASE.code() + 0x0027),
  ERROR_FFMPEG_COLOR_SPACE_TYPE_NULL(ERROR_FFMPEG_BASE.code() + 0x0028),
  ERROR_FFMPEG_COLOR_SPACE_NUM_COMPONENT_NULL(ERROR_FFMPEG_BASE.code() + 0x0029),
  ERROR_FFMPEG_AUDIO_LINE_UNAVAILABLE(ERROR_FFMPEG_BASE.code() + 0x002A),

  ERROR_SYSTEM_BASE(0x00000A00),
  // Jumped these four error codes for compatibility with javafx
  // ERROR_SYSTEM_NOT_IMPLEMENTED(ERROR_SYSTEM_BASE.code()+0x0001),
  // ERROR_SYSTEM_MEMORY_ALLOCATION(ERROR_SYSTEM_BASE.code()+0x0002),
  // ERROR_SYSTEM_OS_UNSUPPORTED(ERROR_SYSTEM_BASE.code()+0x0003),
  // ERROR_SYSTEM_PLATFORM_UNSUPPORTED(ERROR_SYSTEM_BASE.code()+0x0004),

  // Ffmpeg uses UNIX standard error codes that we loop back here
  ERROR_SYSTEM_EPERM(ERROR_SYSTEM_BASE.code() + 0x0005),
  ERROR_SYSTEM_ENOENT(ERROR_SYSTEM_BASE.code() + 0x0006),
  ERROR_SYSTEM_ESRCH(ERROR_SYSTEM_BASE.code() + 0x0007),
  ERROR_SYSTEM_EINTR(ERROR_SYSTEM_BASE.code() + 0x0008),
  ERROR_SYSTEM_EIO(ERROR_SYSTEM_BASE.code() + 0x0009),
  ERROR_SYSTEM_ENXIO(ERROR_SYSTEM_BASE.code() + 0x000A),
  ERROR_SYSTEM_E2BIG(ERROR_SYSTEM_BASE.code() + 0x000B),
  ERROR_SYSTEM_ENOEXEC(ERROR_SYSTEM_BASE.code() + 0x000C),
  ERROR_SYSTEM_EBADF(ERROR_SYSTEM_BASE.code() + 0x000D),
  ERROR_SYSTEM_ECHILD(ERROR_SYSTEM_BASE.code() + 0x000E),
  ERROR_SYSTEM_EAGAIN(ERROR_SYSTEM_BASE.code() + 0x000F),
  ERROR_SYSTEM_ENOMEM(ERROR_SYSTEM_BASE.code() + 0x0010),
  ERROR_SYSTEM_EACCES(ERROR_SYSTEM_BASE.code() + 0x0011),
  ERROR_SYSTEM_EFAULT(ERROR_SYSTEM_BASE.code() + 0x0012),
  // ERROR_SYSTEM_ENOTBLK(ERROR_SYSTEM_BASE.code()+0x0013), // Not available on windows in errno.h
  ERROR_SYSTEM_EBUSY(ERROR_SYSTEM_BASE.code() + 0x0014),
  ERROR_SYSTEM_EEXIST(ERROR_SYSTEM_BASE.code() + 0x0015),
  ERROR_SYSTEM_EXDEV(ERROR_SYSTEM_BASE.code() + 0x0016),
  ERROR_SYSTEM_ENODEV(ERROR_SYSTEM_BASE.code() + 0x0017),
  ERROR_SYSTEM_ENOTDIR(ERROR_SYSTEM_BASE.code() + 0x0018),
  ERROR_SYSTEM_EISDIR(ERROR_SYSTEM_BASE.code() + 0x0019),
  ERROR_SYSTEM_EINVAL(ERROR_SYSTEM_BASE.code() + 0x001A),
  ERROR_SYSTEM_ENFILE(ERROR_SYSTEM_BASE.code() + 0x001B),
  ERROR_SYSTEM_EMFILE(ERROR_SYSTEM_BASE.code() + 0x001C),
  ERROR_SYSTEM_ENOTTY(ERROR_SYSTEM_BASE.code() + 0x001D),
  // ERROR_SYSTEM_ETXTBSY(ERROR_SYSTEM_BASE.code()+0x001E), // Not available on windows in errno.h
  ERROR_SYSTEM_EFBIG(ERROR_SYSTEM_BASE.code() + 0x001F),
  ERROR_SYSTEM_ENOSPC(ERROR_SYSTEM_BASE.code() + 0x0020),
  ERROR_SYSTEM_ESPIPE(ERROR_SYSTEM_BASE.code() + 0x0021),
  ERROR_SYSTEM_EROFS(ERROR_SYSTEM_BASE.code() + 0x0022),
  ERROR_SYSTEM_EMLINK(ERROR_SYSTEM_BASE.code() + 0x0023),
  ERROR_SYSTEM_EPIPE(ERROR_SYSTEM_BASE.code() + 0x0024),
  ERROR_SYSTEM_EDOM(ERROR_SYSTEM_BASE.code() + 0x0025),
  ERROR_SYSTEM_ERANGE(ERROR_SYSTEM_BASE.code() + 0x0026),
  ERROR_SYSTEM_EDEADLK(ERROR_SYSTEM_BASE.code() + 0x0027),
  ERROR_SYSTEM_ENAMETOOLONG(ERROR_SYSTEM_BASE.code() + 0x0028),
  ERROR_SYSTEM_ENOLCK(ERROR_SYSTEM_BASE.code() + 0x0029),
  ERROR_SYSTEM_ENOSYS(ERROR_SYSTEM_BASE.code() + 0x002A),
  ERROR_SYSTEM_ENOTEMPTY(ERROR_SYSTEM_BASE.code() + 0x002B),

  ERROR_FUNCTION_BASE(0x00000B00),
  ERROR_FUNCTION_PARAM(ERROR_FUNCTION_BASE.code() + 0x0001),
  ERROR_FUNCTION_PARAM_NULL(ERROR_FUNCTION_BASE.code() + 0x0002),

  ERROR_JNI_BASE(0x00000C00), // JNI upcall from native into Java
  ERROR_JNI_SEND_PLAYER_MEDIA_ERROR_EVENT(ERROR_JNI_BASE.code() + 0x0001),
  ERROR_JNI_SEND_PLAYER_HALT_EVENT(ERROR_JNI_BASE.code() + 0x0002),
  ERROR_JNI_SEND_PLAYER_STATE_EVENT(ERROR_JNI_BASE.code() + 0x0003),
  ERROR_JNI_SEND_NEW_FRAME_EVENT(ERROR_JNI_BASE.code() + 0x0004),
  ERROR_JNI_SEND_FRAME_SIZE_CHANGED_EVENT(ERROR_JNI_BASE.code() + 0x0005),
  ERROR_JNI_SEND_END_OF_MEDIA_EVENT(ERROR_JNI_BASE.code() + 0x0006),
  ERROR_JNI_SEND_AUDIO_TRACK_EVENT(ERROR_JNI_BASE.code() + 0x0007),
  ERROR_JNI_SEND_VIDEO_TRACK_EVENT(ERROR_JNI_BASE.code() + 0x0008),
  ERROR_JNI_SEND_METADATA_EVENT(ERROR_JNI_BASE.code() + 0x0009),
  ERROR_JNI_SEND_MARKER_EVENT(ERROR_JNI_BASE.code() + 0x000A),
  ERROR_JNI_SEND_BUFFER_PROGRESS_EVENT(ERROR_JNI_BASE.code() + 0x000B),
  ERROR_JNI_SEND_STOP_REACHED_EVENT(ERROR_JNI_BASE.code() + 0x000C),
  ERROR_JNI_SEND_DURATION_UPDATE_EVENT(ERROR_JNI_BASE.code() + 0x000D),
  ERROR_JNI_SEND_AUDIO_SPECTRUM_EVENT(ERROR_JNI_BASE.code() + 0x000E);

  private static final Map<Integer, String> codeToDescription = new HashMap<>();
  private static final Map<Integer, MediaError> codeToError = new HashMap<>();

  static {
    // Build a map for all error objects
    for (MediaError mediaError : MediaError.values()) {
      codeToError.put(mediaError.code(), mediaError);
    }
    // Build a map for all error descriptions
    try {
      ResourceBundle bundle = ResourceBundle.getBundle("org/datavyu/plugins/ffmpeg/MediaErrors");
      for (MediaError mediaError : MediaError.values()) {
        String description = mediaError.name();
        try {
          description = bundle.getString(description);
        } catch (MissingResourceException e) {
          // nothing to do here
        }
        codeToDescription.put(mediaError.code(), description);
      }
    } catch (MissingResourceException e) {
      // Use the constant name directly if the resource bundle could not be loaded
      for (MediaError mediaError : MediaError.values()) {
        codeToDescription.put(mediaError.code(), mediaError.name());
      }
    }
  }

  private int code;

  MediaError(int code) {
    this.code = code;
  }

  public int code() {
    return code;
  }

  public String description() {
    return codeToDescription.get(code());
  }

  public static MediaError getFromCode(int code) {
    return codeToError.get(code);
  }
}
