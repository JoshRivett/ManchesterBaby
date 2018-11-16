/*
	Name: 			Josh Rivett
	Matric Number: 	170005367
	Module Code: 	AC21009
	References:
		Both functions were taken from my cellular automaton code and adapted for C++ and negative number handling.
*/

#include <cstdlib>
#include <cmath>
#include "binaryConversion.h"

using namespace std;

/* Function for converting a decimal number to a binary array.
	decimal	- the decimal number to be converted.
	*binary	- the array to store the binary number in.
	length	- the length of the array.
*/
int BinaryConversion::toBinary(long decimal, int *binary, int length) {
	//Declares the required variables.
	int i = 0;
	bool negative = false;

	//Checks if the decimal number is negative.
	if (decimal < 0) {
		negative = true;
		decimal = abs(decimal);

	}

	//Initialises all the values in the array to 0.
	for (int i = 0; i < length; i++) {
		binary[i] = 0;
	}
	
	//Converts the rule to an array of binary digits.
	while (decimal > 0) {
		binary[i] = decimal % 2;
		i++;
		decimal /= 2;
	}

	//Checks if the number is supposed to be negative.
	if (negative) {
		//Loops through and inverts 1s to 0s and vice versa.
		for (int i = 0; i < length; i++) {
			if (binary[i] == 0) {
				binary[i] = 1;
			} else {
				binary[i] = 0;
			}
		}

		//Declares and initialises required variables.
		bool add = false;
		i = 0;

		//Loops until 1 is successfully added or the start of the array is reached.
		while(add == false && i < length) {
			//Checks whether the bit is a 1 or 0.
			if (binary[i] == 0) {
				//Sets the bit to 1 and sets add to true as 1 was successfully added.
				binary[i] = 1;
				add = true;
			} else if (binary[i] == 1) {
				//Sets the bit to 0 and carries the 1.
				binary[i] = 0;
			}
			//Increments the counter.
			i++;
		}
	}

	return 0;
}

/* Function to convert an array of binary integers to a decimal number.
	*binaryInt	- pointer to an array of binary integers.
	length		- the length of the array.
	Returns the decimal equivalent to the binary number passed in.
*/
long BinaryConversion::toDecimal(int *binaryInt, int length) {
	//Initialises the required variables.
	char *binaryString = new char[length];
	char *ptr;
	long decimal;
	bool negative = false;

	//Checks the sign bit to see if the binary number is negative.
	if (binaryInt[length-1] == 1) {
		negative = true;
	}

	//Converts the integer array to a character array.
	for (int i = 0; i < length; i++) {
		binaryString[i] = binaryInt[length - (i+1)] + '0';
	}

	//Converts the binary string to a long int.
	decimal = strtol(binaryString, &ptr, 2);

	//Checks if the decimal is supposed to be negative.
	if (negative) {
		//Changes the decimal to the correct negative number.
		decimal-=pow(2, length);
	}

	//Frees the memory allocated for the binary string.
	delete[] binaryString;

	return decimal;
}