#include "menus.h"
#include <iostream>

void Menus::displayMainMenu() {

  int mainMenuVar;

  do {

    std::cout << "What would you like to do today?" << std::endl;
    std::cout << "1. Process Wav Files" << std::endl;
    std::cout << "2. Edit Metadata" << std::endl;
    std::cout << "3. Export CSV" << std::endl;
    std::cout << "0. Exit" << std::endl;

    std::cin >> mainMenuVar;

    std::cout << std::endl;

    switch (mainMenuVar) {
      case 1: // wav processing
              displayWavMenu();
              break;
      
      case 2: // metadata
              displayMetadataMenu();
              break;

      case 3: // export csv
              displayCSVMenu();
              break;
      
      case 0: // exit
              break;
    }

  } while(mainMenuVar != 0);

}

void Menus::displayWavMenu() {

  int userInput;
  do {

    std::cout << "Which effect would you like to use?" << std::endl;
    std::cout << "1. Echo" << std::endl;
    std::cout << "2. Normalization" << std::endl;
    std::cout << "3. Noise Gate" << std::endl;
    std::cout << "0. Exit" << std::endl;

    std::cin >> userInput;

    std::cout << std::endl;

    switch(userInput) {

      case 1: // echo
              break;

      case 2: // normalization
              break;

      case 3: // noise gate
              break;

      case 0: // exit
              break;

    }

  } while (userInput != 0);


}

void Menus::displayMetadataMenu() {
  std::cout << "This part of the function is not complete." << std::endl;
  std::cout << "Please pick something else." << std::endl;
}

void Menus::displayCSVMenu() {
  std::cout << "This part of the function is not complete." << std::endl;
  std::cout << "Please pick something else." << std::endl;
}
