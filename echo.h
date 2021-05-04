/**
 * @file echo.h
 * @author Zach Poole
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ECHO_H
#define ECHO_H
//#include "processor.h"
#include <iostream>
#include <limits>


/**
 * @brief The class for the echo effect
 * 
 * This class contains all of the functions needed to implement the echo effect on a given wav file.
 * 
 */
class Echo {

protected:

  int sampleDelay;


public: 


  /**
   * @brief Construct a new Echo object
   * 
   * Default constructor.
   */
  Echo() = default;


  /**
   * @brief Construct a new Echo object (with parameters)
   * 
   * @param sampleDelay The desired echo delay (in samples, not seconds).
   * 
   * Paramaterized constructor.
   */
  Echo(int sampleDelay);


  /**
   * @brief Destroy the Echo object
   * 
   * Default destructor (the only destructor).
   */
  virtual ~Echo();

  
  /**
   * @brief Adds the echo (echo, echo)
   * 
   * @tparam bufferType 
   * @param buffer 
   * @param bufferSize 
   * @param numChannels
   * 
   * This program creates an echo by adding together an older buffer value with one further in the file, 
   * then making sure it's not blasting the volume by limiting the value with the maximum allowable value in the specified type. 
   */
  template<typename bufferType>
  void processEcho(bufferType *buffer, int bufferSize, int numChannels) {

    bufferType maxValue = std::numeric_limits<bufferType>::max();

    if(numChannels == 1) {

      for(int i = sampleDelay; i < bufferSize; i++) {

        if(((buffer[i] + buffer[i-sampleDelay]) < maxValue)) {

          buffer[i] = ((buffer[i] - ((maxValue) / 2)) *2 ) + ((maxValue) / 2);

          buffer[i] = ((buffer[i] + buffer[i - sampleDelay]) * 0.5);

        }

      }

    }
    else if(numChannels == 2) {

      for(int i = sampleDelay; i < bufferSize; i + 2) {

        if(((buffer[i] + buffer[i-sampleDelay]) < maxValue)) {

          buffer[i] = ((buffer[i] - ((maxValue) / 2)) *2 ) + ((maxValue) / 2);

          buffer[i] = ((buffer[i] + buffer[i - sampleDelay]) * 0.5);

          buffer[i + 1] = ((buffer[i + 1] - ((maxValue) / 2)) *2 ) + ((maxValue) / 2);

          buffer[i + 1] = ((buffer[i + 1] + buffer[i + 1 - sampleDelay]) * 0.5);

        }

      }

    }
    else {
      std::cout << "Error" << std::endl;
    }

  }

};

#endif