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
 
 #include "NWBRecording.h"
 
 using namespace NWBRecording;
 
 NWBRecordEngine::NWBRecordEngine()
 {
	 //Init stuff, if needed
 }
 
 NWBRecordEngine::~NWBRecordEngine()
 {
	 //Deinit stuff, if needed
 }
 
 String::NWBRecordEngine getEngineID() const
 {
	 return "NWB"; //a text identifier
 }
 
 void NWBRecordEngine::openFiles(File rootFolder, int experimentNumber, int recordingNumber)
 {
	 //Called when acquisition starts, to open the files
	 String basepath = rootFolder.getFullPathNAme() + rootFolder.separatorString + "experiment_" + String(experimentNumber);
	 
	 //Either open just one file, or one per processor, or whatever. See the recordIndexes document to see how to know how many 
	 //processors and channels are being recorded and the Binary writer for examples
	 //Also calls startNewRecording for each file to set the structures and prepare them to write.
	 
 }
 
 void NWBRecordEngine::closeFiles()
 {
	 //Called when acquisition stops. Should close the files and leave the processor in a reset status
 }
 
 void NWBRecordEngine::resetChannels()
 {
	 //Called at various points, should reset everything.
 }
 
 void NWBRecordEngine::writeData(int writeChannel, int realChannel, const float* buffer, int size)
 {
		//Writes data for a specific channel (see recordIndexes document)
 }
 
void NWBRecordEngine::writeEvent(int eventType, const MidiMessage& event, int64 timestamp) 
{
	//Writes an event.
}
void NWBRecordEngine::addSpikeElectrode(int index,const  SpikeRecordInfo* elec) 
{
	//Called during chain update by a processor that records spikes. Allows the RecordEngine to gather data about the electrode, which will usually
	//be used in openfiles to be sent to startNewRecording so the electrode info is stored into the file.
}
void NWBRecordEngine::writeSpike(int electrodeIndex, const SpikeObject& spike, int64 timestamp) 
{
		//Writes a spike.
}

RecordEngineManager* NWBRecordEngine::getEngineManager()
{
	//static factory that instantiates the engine manager, which allows to configure recording options among other things. See OriginalRecording to see how to create options for a record engine
	RecordEngineManager* man = new RecordEngineManager("NWB", "NWB", &(engineFactory<BinaryRecording>));
	return man;
	
}