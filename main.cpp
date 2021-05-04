#include <iostream>
#include <limits>
#include <fstream>
#include <filesystem>
#include <dirent.h>
#include <string>
#include <vector>
#include <algorithm>
#include "wav.h"

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    std::cout << "Please enter ./test \'directory name\', or ./test \'help\' for more info." << std::endl;
    return 1;
  }

  std::string argvStr(argv[1]);

  if (argvStr == "help")
  {
    std::cout << "For this program to work, you must enter the name of a directory full of wav files." << std::endl;
    std::cout << "The directory must be in the same location as this program." << std::endl;

    return 1;
  }

  // creates directory pointer
  DIR *directory;

  struct dirent *file;

  // opens directory
  directory = opendir(argv[1]);

  // creates a vector of strings with the filenames
  std::vector<std::string> fileNames;
  std::vector<std::string> wavFileNames;

  // reads in the file names
  while ((file = readdir(directory)) != NULL)
  {
    fileNames.push_back(file->d_name);
  }

  //call the function to read the files if they're wav files

  for (int i = 0; i < fileNames.size(); i++)
  {

    if (fileNames[i].size() > 4)
    {
      
      std::string fileString = fileNames[i];
      // chop up string
      std::string splicedString = fileString.substr(fileString.size() - 4, fileString.size());

      if (splicedString == ".wav")
      {
        std::cout << fileNames[i] << std::endl;
        std::string tempStr =  std::string(argvStr + "/" + fileNames[i]);
        wavFileNames.push_back(tempStr);
        //std::cout << "works here" << std::endl;
      }
    }
  }

  std::cout << "file names" << std::endl;
  for (int i = 0; i < wavFileNames.size(); i++)
  {
    std::cout << wavFileNames[i] << std::endl;
  }

  Wav test;
  test.readFile("waves/yes-8-bit-stereo.wav");
  std::cout << "worked here" << std::endl;

  std::vector<Wav> wavFiles;
  std::vector<Wav> testFiles;
  for(int i = 0; i < wavFileNames.size(); i++) {
    //Wav testFile;
    //wavFiles.emplace_back(testFile);
    Wav wavFiles[i];
    wavFiles[i].readFile(wavFileNames[i]);
    std::cout << wavFiles[i].getNumChannels() << std::endl;
    //std::cout << "worked" << std::endl;
  }
  std::cout << "works here" << std::endl;


  std::cout << wavFiles[1].getNumChannels() << std::endl;


}