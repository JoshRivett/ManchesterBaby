#include <iostream>
#include "babySimulator.h"
#include "binaryConversion.h"

//Using the standard name space.
using namespace std;

int main() {
	BabySimulator baby;
	int instruction;

	baby.loadProgram("BabyTest1-MC.txt");

	while(!baby.getStopLamp()) {
		baby.printOut();
		baby.fetch();
		
		instruction = baby.decode();

		if (instruction == DECODE_FAILED) {
			return 1;
		}

		baby.execute(baby.getCI(), instruction);
	}

	return 0;
}