/** @file */
#include <iostream>

//#include "wav.h"
//#include "waveheader.h"
//#include "echo.h"
//#include "noiseGate.h"
//#include "normalization.h"
//#include "processor.h"

using namespace std;

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main() {
	int choice, delay;
	string wavName;
	cout << "What is the name of the wav File do you to use? ";
	cin >> wavName;
	cout << "What do you want to do?" << endl;
	cout << "1.Echo" << endl;
	cout << "2.Noise Gate" << endl;
	cout << "3.Normalize" << endl;
	cout << "4.See MetaData" << endl;
	cout << "5.Modify Metadata" << endl;
	cout << "6.Export Metadata" << endl;
	cout << "0.End" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	while(choice != 0){
		if(choice == 1){
			cout << "-----------------------------" << endl;
			//echo function
			cout << "What delay would you want your buffer to be set to? ";
			cin >> delay;
			//Wav wav;
			//wav.readFile(wavName);
			//wav = new Echo(delay);
			cout << "-----------------------------" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1.Echo" << endl;
			cout << "2.Noise Gate" << endl;
			cout << "3.Normalize" << endl;
			cout << "4.See MetaData" << endl;
			cout << "5.Modify Metadata" << endl;
			cout << "6.Export Metadata" << endl;
			cout << "0.End" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
		}
		else if(choice == 2){
			cout << "-----------------------------" << endl;
			//Noise Gate Function
			cout << "-----------------------------" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1.Echo" << endl;
			cout << "2.Noise Gate" << endl;
			cout << "3.Normalize" << endl;
			cout << "4.See MetaData" << endl;
			cout << "5.Modify Metadata" << endl;
			cout << "6.Export Metadata" << endl;
			cout << "0.End" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
		}
		else if(choice == 3){
			cout << "-----------------------------" << endl;
			//Normalize Function
			cout << "-----------------------------" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1.Echo" << endl;
			cout << "2.Noise Gate" << endl;
			cout << "3.Normalize" << endl;
			cout << "4.See MetaData" << endl;
			cout << "5.Modify Metadata" << endl;
			cout << "6.Export Metadata" << endl;
			cout << "0.End" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
		}
		else if(choice == 4){
			cout << "-----------------------------" << endl;
			//Print MetaData
			cout << "-----------------------------" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1.Echo" << endl;
			cout << "2.Noise Gate" << endl;
			cout << "3.Normalize" << endl;
			cout << "4.See MetaData" << endl;
			cout << "5.Modify Metadata" << endl;
			cout << "6.Export Metadata" << endl;
			cout << "0.End" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
		}
		else if(choice == 5){
			cout << "-----------------------------" << endl;
			//Modify MetaData
			cout << "-----------------------------" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1.Echo" << endl;
			cout << "2.Noise Gate" << endl;
			cout << "3.Normalize" << endl;
			cout << "4.See MetaData" << endl;
			cout << "5.Modify Metadata" << endl;
			cout << "6.Export Metadata" << endl;
			cout << "0.End" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
		}
		else if(choice == 6){
			cout << "-----------------------------" << endl;
			//Export MetaData
			cout << "-----------------------------" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1.Echo" << endl;
			cout << "2.Noise Gate" << endl;
			cout << "3.Normalize" << endl;
			cout << "4.See MetaData" << endl;
			cout << "5.Modify Metadata" << endl;
			cout << "6.Export Metadata" << endl;
			cout << "0.End" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
		}
		else{
			cout << "-----------------------------" << endl;
			cout << "ENTER A OPTION STATED" << endl;
			cout << "-----------------------------" << endl;
			cout << "What do you want to do?" << endl;
			cout << "1.Echo" << endl;
			cout << "2.Noise Gate" << endl;
			cout << "3.Normalize" << endl;
				cout << "4.See MetaData" << endl;
			cout << "5.Modify Metadata" << endl;
			cout << "6.Export Metadata" << endl;
			cout << "0.End" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
		}
		
	}
	return 0;
}


