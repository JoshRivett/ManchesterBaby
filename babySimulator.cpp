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
	//Adds 1 to the control instruction.
	CI++;

	return SUCCESS;
}
		
/* Function 0: Copy content of the specified line into the CI.
	line - the line of the store to be manipulated.
*/
int BabySimulator::JMP(int line) {
	//Converts the requested store line to decimal and copies it to the control instruction.
	CI = BinaryConversion::toDecimal(store[line], storeBits);

	return SUCCESS;
}
		
/* Function 1: Add the content of the specified line, negated, into the CI.
	line - the line of the store to be manipulated.
*/
int BabySimulator::JRP(int line) {
	//Converts the requested store line to decimal, negates it, and adds it to the control instruction.
	CI += -1 * BinaryConversion::toDecimal(store[line], storeBits);

	return SUCCESS;
}
		
/* Function 2: Copy the content of the specified line, negated, into the accumulator.
	line - the line of the store to be manipulated.
*/
int	BabySimulator::LDN(int line) {
	//Declares the required variables.
	long decimal;
	int copy[storeBits];

	//Converts the requested store line to decimal and negates it.
	decimal = -1 * BinaryConversion::toDecimal(store[line], storeBits);

	//Converts the negated value back to binary.
	BinaryConversion::toBinary(decimal, copy, storeBits);

	//Loops through the accumulator and copies the negated store line bits to each accumulator bit.
	for (int i = 0; i < accumulatorSize; i++) {
		accumulator[i] = copy[i];
	}

	return SUCCESS;
}
		
/* Function 3: Copy the content of the accumulator to the specified store line.
	line - the line of the store to be manipulated.
*/
int	BabySimulator::STO(int line) {
	//Loops through the accumulator and stores each of the bits in the requested store line.
	for (int i = 0; i < accumulatorSize; i++) {
		store[line][i] = accumulator[i];
	}

	return SUCCESS;
}
		
/* Function 4/5: Subtract the content of the specified line from the accumulator.
	line - the line of the store to be manipulated.
*/
int	BabySimulator::SUB(int line) {
	//Declares the required variables.
	long storeValue, accumulatorValue;

	//Converts the requested store line, as well as the accumulator, to decimal values.
	storeValue = BinaryConversion::toDecimal(store[line], storeBits);
	accumulatorValue = BinaryConversion::toDecimal(store[line], storeBits);

	//Subtracts the store value from the accumulator value, converts the result back to binary, and stores it in the accumulator.
	BinaryConversion::toBinary((accumulatorValue-storeValue), accumulator, accumulatorSize);

	return SUCCESS;
}
		
/* Function 6: If the accumulator is less than 0 increment the CI.
	line - the line of the store to be manipulated.
*/
int	BabySimulator::CMP(int line) {
	//Declares the required variables.
	long accumulatorValue;

	//Converts the accumulator value to a decimal number.
	accumulatorValue = BinaryConversion::toDecimal(store[line], storeBits);

	//Checks if the accumulator value is less than 0 and if so, increments the control instruction.
	if (accumulatorValue < 0) {
		incrementCI();
	}

	return SUCCESS;
}
		
/* Function 7: Halt the Baby. */
int	BabySimulator::STP() {


	return SUCCESS;
}