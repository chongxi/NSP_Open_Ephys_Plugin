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
 
 #include "NWBFormat.h"
 using namespace NWBRecording;
 
 NWBFile::NWBFile(String fName) : HDF5FileBase(), filename(fName)
 {
	 //Init stuff
	 readyToOpen=true; //In KWIK this is in initFile, but the new recordEngine methods make it safe for it to be here
 }
 
 NWBFile::~NWBFile()
 {
 }

//All int return values are 0 if succesful, other number otherwise
int NWBFile::createFileStructure()
{
	//This is called when the file is first created (not if it's opened but it already exists)
	//Creates all the common structures, like file version and such
	
	return 0;
}
 
 void NWBFile::startNewRecording(int recordingNumber, int nChannels, NWBInfoStruct* info)
 {
	 //Created each time a new recording is started. Creates the specific file structures and attributes
	 //for that specific recording
	 
	 //Also initialized the datasets
	 dataSet = createDataSet(format,sizeX (usually 0), sizeY, chunk_size, path);
	 if (!dataSet.get())
		 std::cerr << "Error creating dataset" << std::endl;
 }
 
 void NWBFile::stopRecording()
 {
	 //Does whatever needs to do when recording ends, like saving special attributes
	 
	 //Also closes the dataset
	 dataSet = nullptr;
 }
 
 void NWBFile::writeData(whatever)
 {
	 //Totally custom, but probably will call dataSet->writeDataRow at least for channel data. Can call writeDataBlock for others, who knows.
 }
 
 String NWBFile::getFileName()
 {
	 return filename;
 }
 
 