/*
	Name: 			Josh Rivett
	Matric Number: 	170005367
	Module Code: 	AC21009
	References:
		1 - Header comments for the instruction set taken from here:
			https://my.dundee.ac.uk/bbcswebdav/pid-5267414-dt-content-rid-2398945_2/courses/AC21009_CAE_D65_201314/SHARP2001GUIDE%281%29.PDF
*/

#ifndef BABY_SIMULATOR_H
#define BABY_SIMULATOR_H

enum BabyError { SUCCESS };

//Declares the required constand values.
const int storeLines = 32;		//The number of lines the store has.
const int storeBits = 32;		//The number of bits each line in the store can hold.
const int accumulatorSize = 32;	//The number of bits the accumulator can hold.

class BabySimulator {
	private:
		//Declares the fields required by the baby.
		int store[storeLines][storeBits];		//32 lines, each holding 32 bits.
		int accumulator[accumulatorSize];		//Holds results of arithmetic operations.
		long CI;	//Control instruction. Holds line number of next instruction.
		long PI;	//Present instruction. Holds actual opcode to be executed.

	public:
		/* Constructor. */
		BabySimulator();

		/* Destructor. */
		~BabySimulator();

		/* Fetch. */
		int fetch();
		
		/* Decode. */
		int decode();
		
		/* Execute, */
		int execute();
		
		/* Print out. */
		int printOut();

		/* Increments the control instruction by 1. */
		int incrementCI();
		
		/* Function 0: Copy content of the specified line into the CI. */
		int JMP(int);
		
		/* Function 1: Add the content of the specified line, negated, into the accumulator. */
		int JRP(int);
		
		/* Function 2: Copy the content of the specified line, negated, into the accumulator. */
		int	LDN(int);
		
		/* Function 3: Copy the content of the accumulator to the specified store line. */
		int	STO(int);
		
		/* Function 4/5: Subtract the content of the specified line from the accumulator. */
		int	SUB(int);
		
		/* Function 6: If the accumulator is less than 0 increment the CI. */
		int	CMP(int);
		
		/* Function 7: Halt the Baby. */
		int	STP();
};

#endif