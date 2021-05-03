#include <string>
#include <fstream>
#include <iostream>
#include "wav.h"

//reading data from wav file
void Wav::readFile(const std::string &fileName) {
	std::ifstream file(fileName,std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));
		buffer = new unsigned char[waveHeader.data_bytes];
		file.read((char*)buffer, waveHeader.data_bytes);
		file.close();
	}
	
	short* shortBuffer = reinterpret_cast<short*>(buffer);
	short val = shortBuffer[0]; //for 16 bit
}

//returns value of buffer
unsigned char *Wav::getBuffer(){
    return buffer;
}

//writes data to new wav file
void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}

//deletes from heap
Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

//returns size of buffer
int Wav::getBufferSize() const {
    return waveHeader.data_bytes;
}
