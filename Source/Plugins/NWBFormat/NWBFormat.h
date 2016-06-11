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

 #ifndef NWBFORMAT_H
 #define NWBFORMAT_H
 
 #include "HFG5FileFormat.h"
 
 namespace NWBRecording
 {
	 class NWBFile : public HDF5FileBase
	 {
		 public:
		 NWBFile(String fName); //with whatever arguments it's necessary
		 ~NWBFile();
		 void startNewRecording(int recordingNumber, int nChannels, NWBInfoStruct* info); //again, whatever parameters needed, last param is a bogus structure, to be filled with whatever data you needed
		 void stopRecording();
		 void writeData();//ditto
		 //void writeSpikes, weiteEvents, whatever
		 String getFileName() override;
		 
		 protected:
			int createFileStructure() override;
			
		private:
			String filename;
			
			ScopedPointer<HDF5RecordingData> dataSet; //whatever datasets are needed for storing the data, one in each pointer like this
			
			//whatever is needed
			JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NWBFile);
			
	 };
	 
 }
 
 #endif