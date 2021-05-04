#ifndef WAV_H
#define WAV_H

#include "waveheader.h"

class Wav {

public:
	Wav() = default;

	Wav(const Wav &obj) {
		
	}

	void readFile(const std::string fileName);
	void writeFile(const std::string &outFileName);

private:
	unsigned char* buffer = NULL;
	wavHeader wavHeader;

public:
	virtual ~Wav();

public:
	unsigned char *getBuffer();
	int getBufferSize() const;
	short getNumChannels() const;
};

#endif
