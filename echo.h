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
#include "processor.h"
#include <iostream>
#include <limits>

class Echo {

// might not need this
protected:
  /**
  * @brief The delay
  * 
  * The delay in terms of number of samples (not seconds)
  */
  int sampleDelay;


public: 


  /**
   * @brief Construct a new Echo object
   * 
   * Default constructor
   */
  Echo() = default;


  /**
   * @brief Construct a new Echo object (with parameters)
   * 
   * @param sampleDelay 
   * 
   * Paramaterized constructor
   */
  Echo(int sampleDelay);


  /**
   * @brief Destroy the Echo object
   * 
   * Default destructor (the only destructor)
   */
  virtual ~Echo();


  /**
   * @brief Adds the echo (echo, echo) (mono)
   * 
   * @tparam bufferType 
   * @param buffer 
   * @param bufferSize 
   * 
   * This program creates an echo by adding together an older buffer value with one further in the file, 
   * then making sure it's not blasting the volume by limiting the value with the maximum allowable value in the specified type.
   * This is the mono version of the echo.
   */
  template<typename bufferType>
  void processEchoMono(bufferType *buffer, int bufferSize) {


    // TODO : negative values work, but positive doesn't really seem to be in the echo
    //maybe split into a positive and negative section like the noise gate and normalization are

    bufferType maxValue = std::numeric_limits<buffer_type>::max();

    std::cout << maxValue << std::endl;

    for(int i = sampleDelay; i < bufferSize; i++) {

      if(((buffer[i] + buffer[i-sampleDelay]) < maxValue)) {

        buffer[i] = ((buffer[i] - ((maxValue) / 2)) *2 ) + ((maxValue) / 2);

        buffer[i] = ((buffer[i] + buffer[i - sampleDelay]) * 0.5);

      }

    }

  }


  /**
   * @brief Adds the echo (echo, echo) (stereo)
   * 
   * @tparam bufferType 
   * @param buffer 
   * @param bufferSize 
   * 
   * This program creates an echo by adding together an older buffer value with one further in the file, 
   * then making sure it's not blasting the volume by limiting the value with the maximum allowable value in the specified type.
   * This is the stereo version of the echo.
   */
  template<typename bufferType>
  void processEchoStereo(bufferType *buffer, int bufferSize) {

    bufferType maxValue = std::numeric_limits<buffer_type>::max();

    std::cout << maxValue << std::endl;

    for(int i = sampleDelay; i < bufferSize; i + 2) {

      if(((buffer[i] + buffer[i-sampleDelay]) < maxValue)) {

        buffer[i] = ((buffer[i] - ((maxValue) / 2)) *2 ) + ((maxValue) / 2);

        buffer[i] = ((buffer[i] + buffer[i - sampleDelay]) * 0.5);

        buffer[i + 1] = ((buffer[i + 1] - ((maxValue) / 2)) *2 ) + ((maxValue) / 2);

        buffer[i + 1] = ((buffer[i + 1] + buffer[i + 1 - sampleDelay]) * 0.5);

      }

    }

  }

};

#endif