#include "menus.h"

void Menus::displayMainMenu(std::vector<std::string> wavFileNames, std::vector<Wav> wavFiles) {

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
              displayWavMenu(wavFileNames, wavFiles);
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

void Menus::displayWavMenu(std::vector<std::string> wavFileNames, std::vector<Wav> wavFiles) {

  int userInput;

  std::cout << "Which file would you like to modify?" << std::endl;

  for(int i = 0; i < wavFileNames.size(); i++) {
    std::cout << i + 1 << ". " << wavFileNames[i] << std::endl;
  }

  std::cin >> userInput;
  displayEffectsMenu(wavFileNames[userInput], wavFiles[userInput], wavFileNames);

}


void Menus::displayEffectsMenu(std::string wavFileName, Wav wavFile, std::vector<std::string> wavFileNames) {

  int userInput;
  do {

    std::cout << "Which effect would you like to use?" << std::endl;
    std::cout << "1. Echo" << std::endl;
    std::cout << "2. Normalization" << std::endl;
    std::cout << "3. Noise Gate" << std::endl;
    std::cout << "0. Save and Exit" << std::endl;

    std::cin >> userInput;

    std::cout << std::endl;

    Processor processor;

    switch(userInput) {

      case 1: // echo
              processor.processNoiseGate(wavFile.get8BitBuffer(), wavFile.getBufferSize(), wavFile.getNumChannels());
              break;

      case 2: // normalization
              processor.processNormalization(wavFile.get8BitBuffer(), wavFile.getBufferSize());
              break;

      case 3: // noise gate
              processor.processEcho(wavFile.get8BitBuffer(), wavFile.getBufferSize(), wavFile.getNumChannels());
              break;

      case 0: // save and exit
              std::string fileName;
              wavFile.checkIfFileExists(wavFileNames);
              wavFile.writeFile(fileName);
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
