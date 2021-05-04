/**
 * @file noiseGate.h
 * @author Zach Poole
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef NOISE_GATE_H
#define NOISE_GATE_H
#include <iostream>
#include <limits>


/**
 * @brief The class for the noise gate
 * 
 * This class contains all the functions needed to add a noise gate to a supplied wav file.
 * 
 */
class NoiseGate {

  float threshold;

public:
  /**
   * @brief Construct a new Noise Gate object
   * 
   * Default constructor (only constructor).
   */
  NoiseGate() = default;

  /**
   * @brief Destroy the Noise Gate object
   * 
   * Default destructor (only destructor)
   */
  virtual ~NoiseGate();


  /**
   * @brief Adds the noise gate effect
   * 
   * @tparam bufferType The type of buffer (unsigned char * for 8-bit and short* for 16-bit)
   * @param buffer The buffer of the wav file
   * @param bufferSize The size of the buffer
   * @param numChannels The number of channels (1 for mono, 2 for stereo)
   * 
   * This function looks for values below a certain threshold, and sets the values to zero if they fall under it.
   */
  template <typename bufferType>
  void processNoiseGate(bufferType *buffer, int bufferSize, int numChannels) {

    bufferType highest = std::numeric_limits<bufferType>::max() / 2;

    for (int i = 0; i < bufferSize; i++) {
      if (buffer[i] > highest) {
        highest = buffer[i];
      }
    }

    bufferType zeroAudioValue = std::numeric_limits<bufferType>::max() / 2;
    bufferType lowest = std::numeric_limits<bufferType>::max() - highest;
    threshold = threshold / 100;

    if (numChannels == 1) {

      for (int i = 0; i < bufferSize; i++) {

        if ((buffer[i] < ((highest - zeroAudioValue) * threshold + zeroAudioValue)) && (buffer[i] > zeroAudioValue)) {

          buffer[i] = zeroAudioValue;
        }

        else if ((buffer[i] > (zeroAudioValue - (lowest * threshold))) && (buffer[i] < zeroAudioValue)) {

          buffer[i] = zeroAudioValue;
        }
      }
    }
    else if (numChannels == 2) {

      for (int i = 0; i < bufferSize; i + 2) {

        if ((buffer[i] < ((highest - zeroAudioValue) * threshold + zeroAudioValue)) && (buffer[i] > zeroAudioValue)) {

          buffer[i] = zeroAudioValue;
          buffer[i + 1] = zeroAudioValue;
        }

        else if ((buffer[i] > (zeroAudioValue - (lowest * threshold))) && (buffer[i] < zeroAudioValue)) {

          buffer[i] = zeroAudioValue;
          buffer[i + 1] = zeroAudioValue;
        }
      }
    }
    else {
      std::cout << "Error" << std::endl;
    }
  }
};

#endif