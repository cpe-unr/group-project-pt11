#include <string>
#include <fstream>
#include <iostream>
#include "wav.h"

// reading data from wav file
void Wav::readFile(const std::string fileName) {
	std::ifstream file(fileName,std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*)&wavHeader, sizeof(wavHeader));
		buffer = new unsigned char[wavHeader.data_bytes];
		file.read((char*)buffer, wavHeader.data_bytes);
		file.close();

		if(wavHeader.bit_depth == 16) {
			shortBuffer = reinterpret_cast<short*>(buffer);
		}
	}
}

std::string Wav::checkIfFileExists(std::vector<std::string> wavFileNames) {

	std::cout << "Please enter a filename: " << std::endl;

	std::string fileName;
	std::cin >> fileName;

	int index = 0;
	int endLoop = 0;
	do {

		if(fileName == wavFileNames[index] && index < wavFileNames.size()) {
			std::cout << "That filename is already taken, please choose another one." << std::endl;
			std::cin >> fileName;
		}
		else if(fileName != wavFileNames[index] && index < wavFileNames.size()) {
			index++;
		}
		else {
			endLoop = 1;
		}

	} while(endLoop != 1);

	return fileName;

}

// returns value of buffer
unsigned char *Wav::get8BitBuffer(){
	return buffer;
}

short *Wav::get16BitBuffer() {
	return shortBuffer;
}

// writes data to new wav file
void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wavHeader,sizeof(wavHeader));
    outFile.write((char*)buffer, wavHeader.data_bytes);
    outFile.close();
}

// deletes from heap
Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

// returns size of buffer
int Wav::getBufferSize() const {
    return wavHeader.data_bytes;
}

short Wav::getNumChannels() const {
	return wavHeader.num_channels;
}