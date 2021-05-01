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

class Processor : public NoiseGate, Echo, Normalization {



};


#endif