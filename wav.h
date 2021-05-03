#ifndef WAV_H
#define WAV_H

#include "waveheader.h"

class Wav {

public:
	void readFile(const std::string &fileName);
	void writeFile(const std::string &outFileName);

private:
	unsigned char* buffer = NULL;
	wav_header waveHeader;

public:
	virtual ~Wav();

public:
	unsigned char *getBuffer();
	int getBufferSize() const;
};

#endif
