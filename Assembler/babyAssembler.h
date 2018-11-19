/*
	Names:			Christian Hegarty,	Naqash Nadeem,	Nicole Orr,	Josh Rivett,	Shaun Yap
	Matric Number: 	170025705			160010238		170010591	170005367		160006581
	Module Code: 	AC21009
	Team Number:	15
*/

#ifndef BABY_ASSEMBLER_H
#define BABY_ASSEMBLER_H

enum AssemblerError { SUCCESS = 100, FILE_OPEN_FAILED = 101, BAD_FILE = 102, INSTRUCTION_NOT_FOUND = 103, CONVERSION_FAILED = 104 };
enum fields { LABEL, INSTRUCTION, OPERAND };
enum LookUpTable { VAR = -1, JMP = 0, JRP = 1, LDN = 2, STO = 3, SUB = 4, CMP = 6, STP = 7 };

const int maxLines = 32;	//The maximum number of lines the machine code can take up.
const int maxBits = 32;		//The maximum number of bits each line of machine code can store.
const int fields = 3;	//The number of fields in the assembly code (labels, instructions, operands).

class BabyAssembler {
	private:
		//Declares the fields required by the assembler.
		std::string assemblyCode[maxLines][fields];
		int machineCode[maxLines][maxBits];
		int lastLine;

	public:
		/* Constructor. */
		BabyAssembler();

		/* Destructor. */
		~BabyAssembler();

		/* Method for looking up the opcode of a given instruction. */
		int lookUp(std::string instruction);

		/* Method to read an assembly file from file into memory. */
		int loadAssemblyFile(std::string);

		/* Method to convert the loaded assembly file into machine code. */
		int convertToMachineCode();

		/* Method to write the machine code to a file. */
		int writeToFile(std::string);
};

#endif