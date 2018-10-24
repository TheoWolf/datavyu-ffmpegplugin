#include "FfmpegErrorUtils.h"
#include "MediaPlayerErrors.h"
#include <iostream>

#define __STDC_CONSTANT_MACROS
#define inline __inline

#ifndef INT64_C
#define INT64_C(c) (c ## LL)
#define UINT64_C(c) (c ## ULL)
#endif

extern "C" {
	#include "libavutil/common.h"
	#include "libavutil/error.h"
}

int ffmpegToJavaErrNo(int ffmpegErrNo) {
	int err = AVERROR(EINVAL);
	if (ffmpegErrNo == err) {
		std::cout << "EINVAL error" << std::endl;
	}

	switch (ffmpegErrNo) {
	case ERROR_NONE:
		return ERROR_NONE;
	// Map ffmpeg internal errors
	case AVERROR_BSF_NOT_FOUND:
		return ERROR_FFMPEG_BSF_NOT_FOUND;
	case AVERROR_BUG:
		return ERROR_FFMPEG_BUG;
	case AVERROR_BUFFER_TOO_SMALL:
		return ERROR_FFMPEG_BUFFER_TOO_SMALL;
	case AVERROR_DECODER_NOT_FOUND:
		return ERROR_FFMPEG_DECODER_NOT_FOUND;
	case AVERROR_DEMUXER_NOT_FOUND:
		return ERROR_FFMPEG_DEMUXER_NOT_FOUND;
	case AVERROR_ENCODER_NOT_FOUND:
		return ERROR_FFMPEG_ENCODER_NOT_FOUND;
	case AVERROR_EOF:
		return ERROR_FFMPEG_EOF;
	case AVERROR_EXIT:
		return ERROR_FFMPEG_EXIT;
	case AVERROR_EXTERNAL:
		return ERROR_FFMPEG_EXTERNAL;
	case AVERROR_FILTER_NOT_FOUND:
		return ERROR_FFMPEG_FILTER_NOT_FOUND;
	case AVERROR_INVALIDDATA:
		return ERROR_FFMPEG_INVALIDDATA;
	case AVERROR_MUXER_NOT_FOUND:
		return ERROR_FFMPEG_MUXER_NOT_FOUND;
	case AVERROR_OPTION_NOT_FOUND:
		return ERROR_FFMPEG_OPTION_NOT_FOUND;
	case AVERROR_PATCHWELCOME:
		return ERROR_FFMPEG_PATCHWELCOME;
	case AVERROR_PROTOCOL_NOT_FOUND:
		return ERROR_FFMPEG_PROTOCOL_NOT_FOUND;
	case AVERROR_STREAM_NOT_FOUND:
		return ERROR_FFMPEG_STREAM_NOT_FOUND;
	case AVERROR_BUG2:
		return ERROR_FFMPEG_BUG2;
	case AVERROR_EXPERIMENTAL:
		return ERROR_FFMPEG_EXTERNAL;
	case AVERROR_INPUT_CHANGED:
		return ERROR_FFMPEG_INPUT_CHANGED;
	case AVERROR_OUTPUT_CHANGED:
		return ERROR_FFMPEG_OUTPUT_CHANGED;
	case AVERROR_HTTP_BAD_REQUEST:
		return ERROR_FFMPEG_HTTP_BAD_REQUEST;
	case AVERROR_HTTP_UNAUTHORIZED:
		return ERROR_FFMPEG_HTTP_UNAUTHORIZED;
	case AVERROR_HTTP_FORBIDDEN:
		return ERROR_FFMPEG_HTTP_FORBIDDEN;
	case AVERROR_HTTP_NOT_FOUND:
		return ERROR_FFMPEG_HTTP_NOT_FOUND;
	case AVERROR_HTTP_OTHER_4XX:
		return ERROR_FFMPEG_HTTP_OTHER_4XX;
	case AVERROR_HTTP_SERVER_ERROR:
		return ERROR_FFMPEG_HTTP_SERVER_ERROR;
	// Map system errors used by ffmpeg
	case AVERROR(EPERM):
		return ERROR_SYSTEM_EPERM;
	case AVERROR(ENOENT):
		return ERROR_SYSTEM_ENOENT;
	case AVERROR(ESRCH):
		return ERROR_SYSTEM_ESRCH;
	case AVERROR(EINTR):
		return ERROR_SYSTEM_EINTR;
	case AVERROR(EIO):
		return ERROR_SYSTEM_EIO;
	case AVERROR(ENXIO):
		return ERROR_SYSTEM_ENXIO;
	case AVERROR(E2BIG):
		return ERROR_SYSTEM_E2BIG;
	case AVERROR(ENOEXEC):
		return ERROR_SYSTEM_ENOEXEC;
	case AVERROR(EBADF):
		return ERROR_SYSTEM_EBADF;
	case AVERROR(ECHILD):
		return ERROR_SYSTEM_ECHILD;
	case AVERROR(EAGAIN):
		return ERROR_SYSTEM_EAGAIN;
	case AVERROR(ENOMEM):
		return ERROR_SYSTEM_ENOMEM;
	case AVERROR(EACCES):
		return ERROR_SYSTEM_EACCES;
	case AVERROR(EFAULT):
		return ERROR_SYSTEM_EFAULT;
	case AVERROR(EBUSY):
		return ERROR_SYSTEM_EBUSY;
	case AVERROR(EEXIST):
		return ERROR_SYSTEM_EEXIST;
	case AVERROR(EXDEV):
		return ERROR_SYSTEM_EXDEV;
	case AVERROR(ENODEV):
		return ERROR_SYSTEM_ENODEV;
	case AVERROR(ENOTDIR):
		return ERROR_SYSTEM_ENOTDIR;
	case AVERROR(EISDIR):
		return ERROR_SYSTEM_EISDIR;
	case AVERROR(EINVAL):
		return ERROR_SYSTEM_EINVAL;
	case AVERROR(ENFILE):
		return ERROR_SYSTEM_ENFILE;
	case AVERROR(EMFILE):
		return ERROR_SYSTEM_EMFILE;
	case AVERROR(ENOTTY):
		return ERROR_SYSTEM_ENOTTY;
	case AVERROR(EFBIG):
		return ERROR_SYSTEM_EFBIG;
	case AVERROR(ENOSPC):
		return ERROR_SYSTEM_ENOSPC;
	case AVERROR(ESPIPE):
		return ERROR_SYSTEM_ESPIPE;
	case AVERROR(EROFS):
		return ERROR_SYSTEM_EROFS;
	case AVERROR(EMLINK):
		return ERROR_SYSTEM_EMLINK;
	case AVERROR(EPIPE):
		return ERROR_SYSTEM_EPIPE;
	case AVERROR(EDOM):
		return ERROR_SYSTEM_EDOM;
	case AVERROR(ERANGE):
		return ERROR_SYSTEM_ERANGE;
	case AVERROR(EDEADLK):
		return ERROR_SYSTEM_EDEADLK;
	case AVERROR(ENAMETOOLONG):
		return ERROR_SYSTEM_ENAMETOOLONG;
	case AVERROR(ENOLCK):
		return ERROR_SYSTEM_ENOLCK;
	case AVERROR(ENOSYS):
		return ERROR_SYSTEM_ENOSYS;
	case AVERROR(ENOTEMPTY):
		return ERROR_SYSTEM_ENOTEMPTY;
	}
	return ERROR_FFMPEG_UNKNOWN;
}