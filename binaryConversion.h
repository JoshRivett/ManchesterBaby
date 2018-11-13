/*
	Name: 			Josh Rivett
	Matric Number: 	170005367
	Module Code: 	AC21009
	References:
		Both functions were taken from my cellular automaton code.
*/

#include <cstdlib>

//Using the standard name space.
using namespace std;

class BinaryConversion {
	public:
		/* Function for converting a decimal number to a binary array.
			decimal	- the decimal number to be converted.
			*binary	- the array to store the binary number in.
		*/
		static int toBinary(int decimal, int *binary) {
			int i = 0;

			//Converts the rule to an array of binary digits.
			while (decimal > 0) {
				binary[i] = decimal % 2;
				i++;
				decimal /= 2;
			}

			return 0;
		}

		/* Function to convert an array of binary integers to a decimal number.
			*binaryInt	- pointer to an array of binary integers.
			length		- the length of the array.
			Returns the decimal equivalent to the binary number passed in.
		*/
		static int toDecimal(int *binaryInt, int length) {
			//Initialises the required variables.
			char *binaryString = new char[length];
			char *ptr;
			long decimal;

			//Converts the integer array to a character array.
			for (int i = 0; i < length; i++) {
				binaryString[i] = binaryInt[i] + '0';
			}

			//Converts the binary string to a long int.
			decimal = strtol(binaryString, &ptr, 2);

			//Frees the memory allocated for the binary string.
			delete[] binaryString;

			return decimal;
		}
};