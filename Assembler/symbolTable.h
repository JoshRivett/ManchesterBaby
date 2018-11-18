/* 
  Name: Nicole Orr
  Matric number: 170010591
  Module code: AC21009
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