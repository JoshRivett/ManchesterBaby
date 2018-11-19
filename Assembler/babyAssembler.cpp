/*
	Names:			Christian Hegarty,	Naqash Nadeem,	Nicole Orr,	Josh Rivett,	Shaun Yap
	Matric Number: 	170025705			160010238		170010591	170005367		160006581
	Module Code: 	AC21009
	Team Number:	15
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "babyAssembler.h"
#include "symbolTable.h"
#include "binaryConversion.h"

//Using the standard namespace.
using namespace std;

/* Constructor. */
BabyAssembler::BabyAssembler() {
	//Initialises the last line variable.
	lastLine = 0;

	//Initialises the machine code storage bits to 0.
	for (int i = 0; i < maxLines; i++) {
		for (int j = 0; j < maxBits; j++) {
			machineCode[i][j] = 0;
		}
	}
}

/* Destructor */
BabyAssembler::~BabyAssembler() {}

/* Method for looking up the opcode of a given instruction.
	instruction - the instruction to find the matching opcode of.
*/
int BabyAssembler::lookUp(string instruction) {
	//Takes the instruction and returns the equivalent opcode if there is one.
	if (instruction == "JMP") {
		return JMP;
	} else if (instruction == "JRP") {
		return JRP;
	} else if (instruction == "LDN") {
		return LDN;
	} else if (instruction == "STO") {
		return STO;
	} else if (instruction == "SUB") {
		return SUB;
	} else if (instruction == "CMP") {
		return CMP;
	} else if (instruction == "STP") {
		return STP;
	} else if (instruction == "VAR") {
		return VAR;
	} else {
		//No opcode matching the instruction was found in the look up table so an error code is returned.
		return INSTRUCTION_NOT_FOUND;
	}
}

/* Method to read an assembly file from file into memory.
	fileName - the name of the file to read from.
*/
int BabyAssembler::loadAssemblyFile(string fileName) {
	//Declares the required variables.
	int lineNumber = 0, i;
	bool comment;
	string line, field[3];

	//Tries to open the code file.
	ifstream assemblyFile(fileName);

	//Checks if the file was successfully opened.
	if (assemblyFile.is_open()) {
		cout << " Loaded Assembly Code" << endl << "----------------------" << endl;

		//Loops while the end of the file has not been reached.
		while (!assemblyFile.eof()) {
			//Checks if the assembly file contains too many lines for the assembler to hold.
			if (lineNumber > maxLines) {
				//There are too many lines for the store to hold so an error code is returned.
				cout << "Error: Too many lines in file." << endl;
				return BAD_FILE;
			}

			//Gets the next line from file.
			getline(assemblyFile, line);

			//Checks if the current line is a comment or empty.
			if (line.find(";") == 0 || line == "") {
				comment = true;
			}

			//Strips the current line of its comment if it had one.
			line = line.substr(0, line.find(";"));

			//Checks if the line was a comment.
			if (!comment) {
				stringstream ssin(line);
				i = 0;

				//Splits the line into the individual fields.
				while (ssin.good() && i < 3) {
					ssin >> field[i];
					i++;
				}

				//Moves the fields along one if there is no label.
				if (field[0].find(":") == string::npos) {
					field[2] = field[1];
					field[1] = field[0];
					field[0] = "";
				//Removes the colon from the label.
				} else {
					field[0] = field[0].substr(0, field[0].find(":"));
				}

				//Stores the line in memory.
				for (int i = 0; i < fields; i++) {
					assemblyCode[lineNumber][i] = field[i];
					cout << assemblyCode[lineNumber][i] << "\t";
				}

				cout << endl;

				//Empties the field array.
				for (int i = 0; i < 3; i++) {
					field[i] = "";
				}

				//Checks if the line is empty.
				if (assemblyCode[lineNumber][INSTRUCTION] != "") {
					//Increments the line number counter.
					lineNumber++;
				}
			} else {
				//Resets the comment variable.
				comment = false;
			}
		}

		//Stores the last line that contains code.
		lastLine = lineNumber;

		//Closes the file.
		assemblyFile.close();
	} else {
		//File was not opened successfully so an error code is returned.
		cout << "Error: Unable to open file '" << fileName << "'." << endl;
		return FILE_OPEN_FAILED;
	}

	cout << endl << "Assembly code loaded successfully." << endl;
	return SUCCESS;
}

/* Method to convert the loaded assembly file into machine code. */
int BabyAssembler::convertToMachineCode() {
	//Declares the required variables.
	SymbolTable symbolTable;
	string currentField;
	int instruction, symbolLine, instructionCode[3], address[5], var[32];
	long value;
	bool variable = false;

	cout << endl << " Starting first pass through of code." << endl << "--------------------------------------" << endl;

	//First pass through code.
	for (int line = 0; line < lastLine; line++) {
		for (int field = 0; field < fields; field++) {
			//Store the current field of the assembly code.
			currentField = assemblyCode[line][field];

			//Checks whether the field is a label, instruction, or operand.
			switch (field) {
				case LABEL:
					//Checks if there is a label at the current field.
					if (currentField != "") {
						//Adds the label to the symbol code along with its line number.
						symbolTable.addSymbol(currentField, line);
					}
					break;

				case INSTRUCTION:
					//Looks up the opcode of the instruction in the current field.
					instruction = lookUp(currentField);

					//Checks if the instruction was found successfully.
					if (instruction == INSTRUCTION_NOT_FOUND) {
						//The instruction could not be found so the conversion is aborted.
						cout << "Error: Unknown instruction '" << instruction << "' on line " << line << "." << endl;
						return CONVERSION_FAILED;

					//Checks if current line is to be declared as a variable.
					} else if (instruction == VAR) {
						variable = true;

					//Otherwise, the opcode is converted to machine code.
					} else {
						BinaryConversion::toBinary(instruction, instructionCode, 3);

						//Stores the opcode in the 13th, 14th, and 15th bit of the current machine code line.
						for (int i = 0; i < 3; i++) {
							machineCode[line][i+13] = instructionCode[i];
						}
					}
					break;

				case OPERAND:
					//Checks whether there is an operand in the current field.
					if (currentField != "") {
						//Tries to parse the string into the value variable.
						istringstream ss(currentField);
						ss >> value;

						//Checks if the operand is a variable value.
						if (variable) {
							//Checks if parsing the string to the value variable failed.
							if (ss.fail()) {
								//The parse failed so an error code is returned.
								cout << "Error: Bad variable value on line " << line << ". Variables must be a valid integer." << endl;
								return CONVERSION_FAILED;
							}

							//The variable value is converted to binary.
							BinaryConversion::toBinary(value, var, maxBits);

							//The variable value is stored in the current line of machine code.
							for (int i = 0; i < maxBits; i++) {
								machineCode[line][i] = var[i];
							}

							//The variable boolean is reset.
							variable = false;

						//Otherwise the operand is an address.
						} else {
							//Checks if a memory address was given directly.
							if (!ss.fail()) {
								//Converts the address to binary.
								BinaryConversion::toBinary(value, address, 5);

								//Stores the address at the start of the current line of machine code.
								for (int i = 0; i < 5; i++) {
									machineCode[line][i] = address[i];
								}
							//Otherwise, a label was given and so the address will be converted on the second pass through.
							} else {
								cout << "Waiting for symbol '" << currentField << "' on line " << line << "." << endl;
							}
						}
					}
					break;
			}
		}
	}

	cout << endl << " Starting second pass through of code." << endl << "---------------------------------------" << endl;

	//Second pass through code (just operands).
	for (int line = 0; line < lastLine; line++) {
		//Stores the current field of the assemble code. 
		currentField = assemblyCode[line][OPERAND];

		//Tries to parse the string into the value variable.
		istringstream ss(currentField);
		ss >> value;

		//Checks if the current field is a symbol.
		if (currentField != "" && ss.fail()) {
			//Gets the corresponding line number of the symbol used.
			symbolLine = symbolTable.getSymbolLine(currentField);

			//Checks if the symbol was found in the symbol table.
			if (symbolLine != -1) {
				//Converts the symbol's line to binary.
				BinaryConversion::toBinary(symbolLine, address, 5);

				//Stores the address at the start of the current line of machine code.
				for (int i = 0; i < 5; i++) {
					machineCode[line][i] = address[i];
				}
			} else {
				//The symbol couldn't be found in the symbol table so an error code is returned.
				cout << "Error: Symbol '" << currentField << "' on line " << line << " not declared." << endl;
				return CONVERSION_FAILED;
			}
		}
		cout << "Line " << line << " converted successfully." << endl;
	}

	cout << endl << "Assembly code successfully converted to machine code." << endl;
	return SUCCESS;
}

/* Method to write the machine code to a file.
	fileName - the name of the file to write to.
*/
int BabyAssembler::writeToFile(string fileName) {
	//Tries to open the code file.
	ofstream machineCodeFile(fileName);

	cout << endl << " Writing machine code to file." << endl << "-------------------------------" << endl;

	//Checks if the file was successfully opened.
	if (machineCodeFile.is_open()) {
		//Writes the machine code to file.
		for (int i = 0; i < lastLine; i++) {
			for (int j = 0; j < maxBits; j++) {
				machineCodeFile << machineCode[i][j];
			}
			machineCodeFile << endl;
			cout << "Line " << i << " written to file." << endl;
		}

	} else {
		//File was not opened successfully so an error code is returned.
		cout << "Error: Unable to open file '" << fileName << "'." << endl;
		return FILE_OPEN_FAILED;
	}

	cout << endl << "Machine code successfully written to file '" << fileName << "'." << endl;
	return SUCCESS;
}