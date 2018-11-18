/*
	Name: 			Josh Rivett
	Matric Number: 	170005367
	Module Code: 	AC21009
*/

#include <iostream>
#include "babyAssembler.h"
#include "binaryConversion.h"

//Using the standard name space.
using namespace std;

enum MainError { NO_ARGUMENT = 101, LOAD_FAILED = 102, CONVERT_TO_MACHINE_CODE_FAILED = 103, WRITE_FAILED = 104 };

/* The main function of the program.
	argc	- the number of arguments passed to the program.
	*argv	- the array of arguments passed to the program.
*/
int main(int argc, char *argv[]) {
	//Declares the required variables.
	BabyAssembler assembler;
	string fileIn, fileOut;

	//Checks if any command line arguments were given.
	if (argc == 2) {
		fileIn = argv[1];
		fileOut = "output.txt";
	} else if (argc > 2) {
		fileIn = argv[1];
		fileOut = argv[2];
	} else {
		cout << "Error: No file name given." << endl;
		return NO_ARGUMENT;
	}

	//Tries to load the assembly code from file.
	if (assembler.loadAssemblyFile(fileIn) != SUCCESS) {
		return LOAD_FAILED;
	}

	//Tries to convert the assembly code to machine code.
	if (assembler.convertToMachineCode() != SUCCESS) {
		return CONVERT_TO_MACHINE_CODE_FAILED;
	}

	//Tries to write the machine code to file.
	if (assembler.writeToFile(fileOut) != SUCCESS) {
		return WRITE_FAILED;
	}	

	return 0;
}