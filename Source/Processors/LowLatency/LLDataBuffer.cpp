/*
------------------------------------------------------------------

This file is part of the Open Ephys GUI
Copyright (C) 2014 Open Ephys

------------------------------------------------------------------

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "LLDataBuffer.h"

LLDataBuffer::LLDataBuffer() : fifo(1), curChannel(-1), wSize(-1)
{
}

LLDataBuffer::~LLDataBuffer()
{
}

void LLDataBuffer::setBufferSize(int numChannels, int numSamples)
{
	fifo.setTotalSize(numSamples);
	data.malloc(numSamples * numChannels);
	nChannels = numChannels;
	dataPtr = data.getData();
}

float* LLDataBuffer::getSamplePtr()
{
	int a1, a2, s1, s2;
	float* addr;
	fifo.prepareToRead(1, a1, s1, a2, s2);
	if (s1 > 0)
		addr = dataPtr + a1*nChannels;
	else
		addr = nullptr;
	fifo.finishedRead(s1 + s2);
	return addr;
}

void LLDataBuffer::startSampleWrite()
{
	int a1, a2, s1, s2;
	fifo.prepareToWrite(1, a1, s1, a2, s2);
	curChannel = 0;
	wSize = s1 + s2;
	writePtr = dataPtr + a1*nChannels;
}

void LLDataBuffer::stopSampleWrite()
{
	if (wSize < 0) return;
	fifo.finishedWrite(wSize);
}

void LLDataBuffer::writeChannelSample(float value)
{
	if (curChannel < 0 || curChannel >= nChannels)
		return;

	*(writePtr + curChannel) = value;
	curChannel++;
}

void LLDataBuffer::flush()
{
	fifo.reset();
}