#include <iostream>
#include "babySimulator.h"
#include "binaryConversion.h"

//Using the standard name space.
using namespace std;

int main() {
	BabySimulator baby;
	int instruction;
	int error;

	baby.loadProgram("BabyTest1-MC.txt");

	while(!baby.getStopLamp()) {
		baby.printOut();
		baby.fetch();
		
		instruction = baby.decode();

		if (instruction == DECODE_FAILED) {
			return 1;
		}

		error = baby.execute(baby.getAddress(), instruction);

		if (error == EXECUTE_FAILED) {
			return 2;
		}
	}

	return 0;
}