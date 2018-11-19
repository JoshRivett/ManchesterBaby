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

/* Function to run the simulation. */
int simulate(string fileName) {
	//Declares the required variables.
	BabySimulator baby;
	int instruction;
	int error;

	//Tries to load the program from file.
	if (baby.loadProgram(fileName) != SUCCESS) {
		return LOAD_FAILED;
	}

	//Prints the starting state of the baby.
	baby.printOut();

	//Runs the fetch execute cycle until the program is complete.
	while(!baby.getStopLamp()) {
		cout << "Fetch" << endl << "-----------------";

		//Waits until the user gives input to initiate the next step.
		cin.get();

		//Fetches the instruction.
		baby.fetch();

		cout << "Decode" << endl << "-----------------";

		//Waits until the user gives input to initiate the next step.
		cin.get();
		
		//Decodes the instruction.
		instruction = baby.decode();

		//Checks if the decode operation failed.
		if (instruction == DECODE_FAILED) {
			return GET_DECODE_FAILED;
		}

		cout << endl << "Execute" << endl << "-----------------";

		//Waits until the user gives input to initiate the next step.
		cin.get();

		//Executes the instruction.
		error = baby.execute(baby.getAddress(), instruction);

		//Checks if the execution of the instruction failed.
		if (error == EXECUTE_FAILED) {
			return EXECUTION_FAILED;
		}

		cout << endl;

		//Prints the current state of the baby.
		baby.printOut();
	}

	return 0;
}

/* The main function of the program.
	argc	- the number of arguments passed to the program.
	*argv	- the array of arguments passed to the program.
*/
int main(int argc, char *argv[]) {
	//Declares the required variables.
	string fileName;

	//Checks if any command line arguments were given.
	if (argc > 1) {
		//Runs the simulator with the command line argument as the file name.
		fileName = argv[1];
		simulate(fileName);
	} else {
		//No arguments were given so an error code is returned.
		cout << "Error: No file name given." << endl;
		return NO_ARGUMENT;
	}

	return 0;
}