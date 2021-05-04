#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <vector>
#include "wav.h"
#include "processor.h"

/**
 * @brief This class contains the functions pretty much all of the user interaction 
 * 
 */
class Menus {

public:

  /**
   * @brief This function displays the main menu
   * 
   * @param wavFileNames The vector of wav file names
   * @param wavFiles The vector of wav files
   * 
   * This function displays the main menu, receives user input, and directs them to another menu based off of that input
   */
  void displayMainMenu(std::vector<std::string> wavFileNames, std::vector<Wav> wavFiles);


  /**
   * @brief This function displays the menu for choosing a wav file
   * 
   * @param wavFileNames The vector of wav file names
   * @param wavFiles The vector of wav files
   * 
   * This function displays the wav menu, receives user input, and directs them to another menu based off of that input
   */
  void displayWavMenu(std::vector<std::string> wavFileNames, std::vector<Wav> wavFiles);


  /**
   * @brief This function displays the menu for choosing which effect to apply to the wav file
   * 
   * @param wavFileName The name of the wav file to modify
   * @param wavFile The wav file to modify
   * @param wavFileNames The vector of wav file names
   * 
   * This function displays the menu asking the user which effect they want to apply to the wav file.
   * Based off of the user input, it calls the appropriate function to edit the wav file.
   */
  void displayEffectsMenu(std::string wavFileName, Wav wavFile, std::vector<std::string> wavFileNames);


  /**
   * @brief The function to display the metadata menu
   * 
   * Right now this function does nothing. If I had more time I would make it so that this function displays the metadata menu,
   * and based off of user input calls the function that they need to edit the metadata.
   * 
   */
  void displayMetadataMenu();


  /**
   * @brief The function to display the CSV menu
   * 
   * Right now this function does nothing. If I had more time, I would make it so that this function displays the menu for printing the CSV file.
   * 
   */
  void displayCSVMenu();

};

#endif