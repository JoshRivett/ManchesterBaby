/*
	Name: 			Josh Rivett
	Matric Number: 	170005367
	Module Code: 	AC21009
*/

#include <iostream>
#include "babySimulator.h"
#include "binaryConversion.h"

//Using the standard name space.
using namespace std;

enum MainError { NO_ARGUMENT = 101, LOAD_FAILED = 102, GET_DECODE_FAILED = 103, EXECUTION_FAILED = 104 };

/* The main function of the program.
	argc	- the number of arguments passed to the program.
	*argv	- the array of arguments passed to the program.
*/
int main(int argc, char *argv[]) {
	//Declares the required variables.
	BabySimulator baby;
	int instruction;
	int error;
	string fileName;

	//Checks if any command line arguments were given.
	if (argc > 1) {
		fileName = argv[1];
	} else {
		cout << "Error: No file name given." << endl;
		return NO_ARGUMENT;
	}

	//Tries to load the program from file.
	if (baby.loadProgram(fileName) != SUCCESS) {
		return LOAD_FAILED;
	}

	//Prints the starting state of the baby.
	baby.printOut();

	//Runs the fetch execute cycle until the program is complete.
	while(!baby.getStopLamp()) {
		//Fetches the instruction.
		baby.fetch();
		
		//Decodes the instruction.
		instruction = baby.decode();

		//Checks if the decode operation failed.
		if (instruction == DECODE_FAILED) {
			return GET_DECODE_FAILED;
		}

		//Executes the instruction.
		error = baby.execute(baby.getAddress(), instruction);

		//Checks if the execution of the instruction failed.
		if (error == EXECUTE_FAILED) {
			return EXECUTION_FAILED;
		}

		//Prints the current state of the baby.
		baby.printOut();
	}

	return 0;
}