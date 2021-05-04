/**
 * @file processor.h
 * @author Zach Poole
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "echo.h"
#include "noiseGate.h"
#include "normalization.h"


/**
 * @brief The processor class is used to combine the different effects
 * 
 * The processor class inherits from the noise gate, echo, and normalization classes, so that all of their various effects can be applied to one object.
 * 
 */
class Processor: public NoiseGate, public Echo, public Normalization {



};


#endif