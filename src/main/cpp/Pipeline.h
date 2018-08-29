/*
 * Copyright (c) 2010, 2015, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include <stdint.h>
#include <sys/stat.h>
#include "PipelineOptions.h"
#include "AudioVideoFormats.h"


class CMedia;
class CJavaPlayerEventDispatcher;

/**
 * class CPipeline
 *
 * Underlying object that interfaces the JNI layer to the actual media engine
 */
class CPipeline
{
public:
    enum PlayerState
    {
        Unknown = 0,
        Ready = 1,
        Playing = 2,
        Paused = 3,
        Stopped = 4,
        Stalled = 5,
        Finished = 6,
        Error = 7
    };

public:
    CPipeline(CPipelineOptions* pOptions=NULL);
    virtual ~CPipeline();

    void                    SetEventDispatcher(CJavaPlayerEventDispatcher* pEventDispatcher);

    virtual uint32_t        Init(const char * filename) = 0;
    virtual void            Dispose();

    virtual uint32_t        Play() = 0;
    virtual uint32_t        Stop() = 0;
    virtual uint32_t        Pause() = 0;
    virtual uint32_t        StepForward() = 0;
    virtual uint32_t        Finish() = 0;

    virtual uint32_t        Seek(double dSeekTime) = 0;

    virtual uint32_t        GetDuration(double* pdDuration) = 0;
    virtual uint32_t        GetStreamTime(double* pdStreamTime) = 0;
	virtual uint32_t		GetFps(double* pdFps) = 0;

    virtual uint32_t        SetRate(float fRate) = 0;
    virtual uint32_t        GetRate(float* pfRate) = 0;

    virtual uint32_t        SetVolume(float fVolume) = 0;
    virtual uint32_t        GetVolume(float* pfVolume) = 0;

    virtual uint32_t        SetBalance(float fBalance) = 0;
    virtual uint32_t        GetBalance(float* pfBalance) = 0;

    virtual uint32_t        SetAudioSyncDelay(long lMillis) = 0;
    virtual uint32_t        GetAudioSyncDelay(long* plMillis) = 0;

protected:
	CJavaPlayerEventDispatcher* m_pEventDispatcher;
	CPipelineOptions*			m_pOptions;
    PlayerState					m_PlayerState;
	PlayerState					m_PlayerPendingState; // This is necessary to get from stalled into the next correct state

	void UpdatePlayerState(PlayerState newState);
	void SetPlayerState(PlayerState newPlayerState, bool bSilent);
};

#endif  //_PIPELINE_H_
