/**
 * @file normalization.h
 * @author Zach Poole
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef NORMALIZATION_H
#define NORMALIZATION_H
//#include "Processor.h"
#include <iostream>
#include <limits>


class Normalization {

public:

  /**
   * @brief Construct a new Normalization object
   * 
   * Default constructor (only constructor)
   */
  Normalization() = default;


  /**
   * @brief Destroy the Normalization object
   * 
   * Default destructor (only destructor)
   */
  virtual ~Normalization();


  /**
   * @brief Normalizes the audio
   * 
   * @tparam bufferType 
   * @param buffer 
   * @param bufferSize 
   * 
   * Multiplies each value in the buffer by the new max value / the current max value
   */
  template<typename bufferType>
  void processNormalization(bufferType *buffer, int bufferSize) {


    // TODO : all of this math needs to be redone
    // actually I think I was right the first time
    bufferType highestAllowedValue = std::numeric_limits<bufferType>::max();
    
    bufferType highestValue = std::numeric_limits<bufferType>::max() / 2;
    for(int i = 0; i < bufferSize; i++) {
      if(buffer[i] > highestValue) {
        highestValue = buffer[i];
      }
    }

    bufferType zeroAudioValue = std::numeric_limits<bufferType>::max() / 2;
    bufferType lowestValue = std::numeric_limits<bufferType>::max() - highestValue;

    float multiplyConst = float(highestAllowedValue) / float(highestValue);
    

    std::cout << multiplyConst << std::endl;
    //std::cout << int(0.75) << std::endl;


    for(int i = 0; i < bufferSize; i++) {

      if(buffer[i] > zeroAudioValue) {
        //std::cout << "goog" << std::endl;
        //buffer[i] = buffer[i] / (highestAllowedValue / buffer[i]);
        //std::cout << "good" << std::endl;
        buffer[i] = buffer[i] * multiplyConst;
      
      }
      else if(buffer[i] < zeroAudioValue) {

        //buffer[i] = buffer[i] / (buffer[i] * highestAllowedValue);
        //std::cout << "good" << std::endl;
        buffer[i] = buffer[i] / multiplyConst;

      }
    
    }

  }

};

#endif