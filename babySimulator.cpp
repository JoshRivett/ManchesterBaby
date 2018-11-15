/*
	Name: 			Josh Rivett
	Matric Number: 	170005367
	Module Code: 	AC21009
*/

#include <cstdlib>
#include "babySimulator.h"
#include "binaryConversion.h"

/* Constructor. */
BabySimulator::BabySimulator() {
	CI = 0;
}

/* Destructor. */
BabySimulator::~BabySimulator() {}

/* Fetch. */
int BabySimulator::fetch() {


	return SUCCESS;
}
		
/* Decode. */
int BabySimulator::decode() {


	return SUCCESS;
}
		
/* Execute. */
int BabySimulator::execute() {


	return SUCCESS;
}
		
/* Print out. */
int BabySimulator::printOut() {


	return SUCCESS;
}

/* Increments the control instruction by 1. */
int BabySimulator::incrementCI() {
	CI++;
	return SUCCESS;
}
		
/* Function 0: Copy content of the specified line into the CI. */
int BabySimulator::JMP() {


	return SUCCESS;
}
		
/* Function 1: Add the content of the specified line, negated, into the accumulator. */
int BabySimulator::JRP() {


	return SUCCESS;
}
		
/* Function 2: Copy the content of the specified line, negated, into the accumulator. */
int	BabySimulator::LDN() {


	return SUCCESS;
}
		
/* Function 3: Copy the content of the accumulator to the specified store line. */
int	BabySimulator::STO() {


	return SUCCESS;
}
		
/* Function 4/5: Subtract the content of the specified line from the accumulator. */
int	BabySimulator::SUB() {


	return SUCCESS;
}
		
/* Function 6: If the accumulator is less than 0 increment the CI. */
int	BabySimulator::CMP() {


	return SUCCESS;
}
		
/* Function 7: Halt the Baby. */
int	BabySimulator::STP() {


	return SUCCESS;
}