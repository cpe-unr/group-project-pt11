#ifndef WAVEHEADER_H
#define WAVEHEADER_H

typedef struct wav_header {

//variables for the wav file formatting

	// RIFF Header
	char riff_header[4];
	int wav_size;
	char wave_header[4];
	
	// Format Header
	char fmt_header[4];
	int fmt_chunk_size;
	short audio_format;
	short num_channels;
	int sample_rate;
	int byte_rate;
	short sample_alignment;
	short bit_depth;

	// Data
	char data_header[4];
	int data_bytes;

} wav_header;

#endif
