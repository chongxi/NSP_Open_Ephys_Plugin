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

#ifndef GENERICLLPROCESSOR_H
#define GENERICLLPROCESSOR_H

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../PluginManager/OpenEphysPlugin.h"
#include "LLDataBuffer.h"

class DataThread;

class PLUGIN_API GenericLLProcessor : public Thread
{
public:
	GenericLLProcessor();
	virtual ~GenericLLProcessor();
	void startAcquisition(int numChannels);
	void stopAcquisition();

	virtual void prepareToAcquire();

	void run();
	void setInputBuffer(LLDataBuffer* bufferPtr);

protected:
	virtual void process(float* dataPtr) = 0;

	int nChannels;
	LLDataBuffer* buffer;

};

#endif