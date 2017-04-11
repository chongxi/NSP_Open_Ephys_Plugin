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

#ifndef LLDATABUFFER_H
#define LLDATABUFFER_H

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../PluginManager/OpenEphysPlugin.h"

class PLUGIN_API LLDataBuffer {
public:
	LLDataBuffer();
	~LLDataBuffer();
	void setBufferSize(int numChannels, int numSamples);
	void getSamplePtr(float**, uint16**);
	void startSampleWrite();
	void stopSampleWrite();
	void writeChannelSample(float value);
	void writeEvent(uint16 data);
	void flush();

private:
	AbstractFifo fifo;
	HeapBlock<float> data;
	HeapBlock<uint16> eventData;
	int nChannels;
	int curChannel;
	float* dataPtr;
	uint16* eventPtr;
	float* writePtr;
	uint16* eventWritePtr;
	int wSize;
};




#endif