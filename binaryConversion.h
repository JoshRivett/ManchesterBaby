/*
	Name: 			Josh Rivett
	Matric Number: 	170005367
	Module Code: 	AC21009
*/

#ifndef BINARY_CLASS_H
#define BINARY_CLASS_H

class BinaryConversion {
	public:
		/* Function for converting a decimal number to a binary array. */
		static long toBinary(long, long*, int);

		/* Function to convert an array of binary integers to a decimal number. */
		static long toDecimal(long*, int);
};

#endif