/*
	Names:			Christian Hegarty,	Naqash Nadeem,	Nicole Orr,	Josh Rivett,	Shaun Yap
	Matric Number: 	170025705			160010238		170010591	170005367		160006581
	Module Code: 	AC21009
	Team Number:	15
*/

#ifndef SYMBOL_TABLE_CLASS
#define SYMBOL_TABLE_CLASS

#include <vector>
#include <string>
#include "symbolClass.h"
#include "binaryConversion.h"

using namespace std;

class SymbolTable
{
	vector<Symbol> symbolTable;

public:
	
	bool isInTable(string label);
	void addSymbol(string label, int line);
	int getSymbolLine(string label);
	void getSymbolLineBin(string label, int *lineBinary, int arrayLength);
};

#endif