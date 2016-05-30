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

#include "GenericLLProcessor.h"

GenericLLProcessor::GenericLLProcessor() : Thread("LLProcessThread")
{
}

GenericLLProcessor::~GenericLLProcessor()
{
}

void GenericLLProcessor::startAcquisition(int numChannels)
{
	nChannels = numChannels;
	prepareToAcquire();
	startThread();	
}

void GenericLLProcessor::stopAcquisition()
{
	prepareToStop();
	if (!stopThread(100))
		std::cerr << "LL Process thread forcefully closed" << std::endl;
}

void GenericLLProcessor::setInputBuffer(LLDataBuffer* bufferPtr)
{
	buffer = bufferPtr;
}

void GenericLLProcessor::prepareToAcquire()
{
}

void GenericLLProcessor::prepareToStop()
{
}

void GenericLLProcessor::run()
{
	float* dataPtr;
	while (!threadShouldExit())
	{
		dataPtr = buffer->getSamplePtr();
		if (dataPtr) 
		{
#ifdef MEASURE_LL_PROC_TIME
			int64 tick = Time::getHighResolutionTicks();
#endif
			process(dataPtr);
#ifdef MEASURE_LL_PROC_TIME
			int64 tock = Time::getHighResolutionTicks() - tick;
			double secs = Time::highResolutionTicksToSeconds(tock);
			run_time_sec += secs;
			if (secs < min ) min = secs;
			else if (secs > max) max = secs;
			total_iter++;
			double mean = run_time_sec / total_iter;
			std::cout << "LL Process time: " << secs << " min: " << min << "max: " << max << " mean: " << mean << std::endl;
#endif

		}
	}
}
