/*
------------------------------------------------------------------

This file is part of the Open Ephys GUI
Copyright (C) 2013 Open Ephys

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


#include "LLThread.h"
#include "RHD2000Thread.h"

#define THRESHOLD_CHECK 10.0f

using namespace PCIeRhythm;

LLThread::LLThread(RHD2000Thread* t) : dataThread(t)
{}

LLThread::~LLThread()
{}

void LLThread::prepareToAcquire()
{
	//setPriority(5);
}

void LLThread::process(float* buffer)
{
	if (buffer[0] > THRESHOLD_CHECK)
		dataThread->setOutputSigs(0x1111);
	else
		dataThread->setOutputSigs(0);
}