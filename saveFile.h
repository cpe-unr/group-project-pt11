#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <iostream>
#include <vector>

/**
 * @brief The interface for saving new wav files
 * 
 * This is the interface for saving wav files, both the buffer part and (if I had more time) the metadata part.
 * 
 */
class ISaveFile {

  /**
   * @brief Writes the file
   * 
   * @param outFileName The name of the file to write
   * 
   * This function gets overloaded to write a new file.
   */
  virtual void writeFile(const std::string &outFileName) = 0;


  /**
   * @brief Checks if a file already exists
   * 
   * @param wavFileNames The vector of wav file names
   * @return std::string Returns an acceptable file name string
   * 
   * This function gets overloaded to check if a user inputted filename already exists, and if not it'll return that file name.
   */
  virtual std::string checkIfFileExists(std::vector<std::string> wavFileNames) = 0;

};

#endif