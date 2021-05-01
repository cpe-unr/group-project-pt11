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
   * @brief add the echo (echo, echo)
   * 
   * @tparam bufferType 
   * @param buffer 
   * @param bufferSize 
   * 
   * This program creates an echo by adding together an older buffer value with one further in the file, 
   * then making sure it's not blasting the volume by limiting the value with the maximum allowable value in the specified type.
   */
  template<typename bufferType>
  void processEcho(bufferType *buffer, int bufferSize) {

    bufferType maxValue = std::numeric_limits<buffer_type>::max();

    std::cout << maxValue << std::endl;

    for(int i = sampleDelay; i < bufferSize; i++) {

      if(((buffer[i] + buffer[i-sampleDelay]) < maxValue)) {

        buffer[i] = ((buffer[i] - ((maxValue) / 2)) *2 ) + ((maxValue) / 2);

        buffer[i] = ((buffer[i] + buffer[i - sampleDelay]) * 0.5);

      }

    }

  }

};

#endif