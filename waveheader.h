#ifndef WAVEHEADER_H
#define WAVEHEADER_H


/**
 * @brief The wavHeader struct
 * 
 * This struct contains most of the data that was read in from the wav file, which is all read through the functions in the wav class.
 * 
 */
typedef struct wavHeader {


	//variables for the wav file formatting

	// RIFF Header
	char riff_header[4];
	int wav_size;
	char wave_header[4];
	
	// Format Header
	char fmt_header[4];
	int fmt_chunk_size;
	short audio_format;
	short num_channels; // 1 for mono, 2 for stereo
	int sample_rate;
	int byte_rate;
	short sample_alignment;
	short bit_depth; // will be 8 for an 8-bit file, 16 for a 16-bit file, etc...

	// Data
	char data_header[4];
	int data_bytes; // number of bytes in data. this is the value that we want to use for all the wav processing loops

	// Metadata
	// put stuff here

} wavHeader;

#endif
