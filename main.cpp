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

int main() {
	//Declares the required variables.
	BabySimulator baby;
	int instruction;
	int error;

	//Loads the program from file and prints the starting state of the baby.
	baby.loadProgram("BabyTest1-MC.txt");
	baby.printOut();

	//Runs the fetch execute cycle until the program is complete.
	while(!baby.getStopLamp()) {
		//Fetches the instruction.
		baby.fetch();
		
		//Decodes the instruction.
		instruction = baby.decode();

		//Checks if the decode operation failed.
		if (instruction == DECODE_FAILED) {
			return 1;
		}

		//Executes the instruction.
		error = baby.execute(baby.getAddress(), instruction);

		//Checks if the execution of the instruction failed.
		if (error == EXECUTE_FAILED) {
			return 2;
		}

		//Prints the current state of the baby.
		baby.printOut();
	}

	return 0;
}