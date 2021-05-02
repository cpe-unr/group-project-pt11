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

class NoiseGate {


  /**
   * @brief The noise gate threshold
   * 
   * If any value falls below the threhshold it gets deleted.
   * (The threshold is stored as a percentage.)
   */
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
   * @brief Sets any values below a threshold to 0 (mono)
   * 
   * @tparam bufferType 
   * @param buffer 
   * @param bufferSize 
   */
  template<typename bufferType>
  void processNoiseGateMono(bufferType *buffer, int bufferSize) {

    bufferType highest = std::numeric_limits<bufferType>::max() / 2;
    
    for(int i = 0; i < bufferSize; i++) {
      if(buffer[i] > highest) {
        highest = buffer[i];
      }
    }

    bufferType zeroAudioValue = std::numeric_limits<bufferType>::max() / 2;
    bufferType lowest = std::numeric_limits<bufferType>::max() - highest;
    threshold = threshold / 100;

    for(int i = 0; i < bufferSize; i++) {

      if((buffer[i] < ((highest - zeroAudioValue) * threshold + zeroAudioValue)) && (buffer[i] > zeroAudioValue)) {

        buffer[i] = zeroAudioValue;

      }

      else if((buffer[i] > (zeroAudioValue - (lowest * threshold))) && (buffer[i] < zeroAudioValue)) {

        buffer[i] = zeroAudioValue;

      }

    }

  }
  

  /**
   * @brief Sets any values below a threshold to 0 (stereo)
   * 
   * @tparam bufferType 
   * @param buffer 
   * @param bufferSize 
   */
  template<typename bufferType>
  void processNoiseGateStereo(bufferType *buffer, int bufferSize) {

    bufferType highest = std::numeric_limits<bufferType>::max() / 2;
    
    for(int i = 0; i < bufferSize; i++) {
      if(buffer[i] > highest) {
        highest = buffer[i];
      }
    }

    bufferType zeroAudioValue = std::numeric_limits<bufferType>::max() / 2;
    bufferType lowest = std::numeric_limits<bufferType>::max() - highest;
    threshold = threshold / 100;

    for(int i = 0; i < bufferSize; i + 2) {

      if((buffer[i] < ((highest - zeroAudioValue) * threshold + zeroAudioValue)) && (buffer[i] > zeroAudioValue)) {

        buffer[i] = zeroAudioValue;
        buffer[i + 1] = zeroAudioValue;

      }

      else if((buffer[i] > (zeroAudioValue - (lowest * threshold))) && (buffer[i] < zeroAudioValue)) {

        buffer[i] = zeroAudioValue;
        buffer[i + 1] = zeroAudioValue;

      }

    }

  }

};

#endif