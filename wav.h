#ifndef WAV_H
#define WAV_H

#include "waveheader.h"
#include "saveFile.h"


/**
 * @brief The wav class
 * 
 * This class contains all the functions related to the wav file (excluding anything metadata related, I didn't have time).
 * It inherits from the ISaveFile class and overrides the writeFile and checkIfFileExists functions.
 * 
 */
class Wav : public ISaveFile {

public:

	/**
	 * @brief Construct a new Wav object
	 * 
	 * Default constructor.
	 */
	Wav() = default;

	/**
	 * @brief Construct a new Wav object
	 * 
	 * @param obj Another wav object
	 * 
	 * Copy constructor.
	 */
	Wav(const Wav &obj) {};


	/**
	 * @brief Reads a wav file
	 * 
	 * @param fileName The name of the wav file
	 * 
	 * This function is given a filename, and it reads the file and inserts the data into the wav object.
	 */
	void readFile(const std::string fileName);


	/**
	 * @brief Writes out a wav file
	 * 
	 * @param outFileName The desired file name
	 * 
	 * This function is given a desired file name, and it takes the info from the wav object and writes it to a new file.
	 */
	void writeFile(const std::string &outFileName) override;


	/**
	 * @brief Checks if a file already exists
	 * 
	 * @param wavFileNames The vector of wav file names
	 * @return std::string Returns an acceptable file name
	 * 
	 * This function asks the user for a file name, and checks if that file already exists.
	 * If it doesn't already exist, it will return the file name.
	 */
	std::string checkIfFileExists(std::vector<std::string> wavFileNames) override;

private:
	unsigned char* buffer = NULL;
	short* shortBuffer = NULL;
	wavHeader wavHeader;

public:

	/**
	 * @brief Destroy the Wav object
	 * 
	 * Default destructor (only destructor).
	 */
	virtual ~Wav();

public:

	/**
	 * @brief Gets the 8-bit buffer
	 * 
	 * @return unsigned char* The 8-bit buffer
	 * 
	 * This function returns the 8-bit buffer (as an unsigned char *).
	 */
	unsigned char *get8BitBuffer();


	/**
	 * @brief Gets the 16-bit buffer
	 * 
	 * @return short* The 16-bit buffer
	 * 
	 * This function returns the 16-bit buffer (as a short*)
	 */
	short*get16BitBuffer();


	/**
	 * @brief Get the Buffer Size object
	 * 
	 * @return int The size of the buffer
	 * 
	 * This function gets the size of the buffer, which is then used for a lot of for loops.
	 */
	int getBufferSize() const;


	/**
	 * @brief Get the Num Channels object
	 * 
	 * @return short The number of channels
	 * 
	 * This function gets the number of channels in the buffer (1 for mono, 2 for stereo).
	 */
	short getNumChannels() const;
};

#endif
