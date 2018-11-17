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

class symbolTable
{
	vector<Symbol> symbolTable;

public:
	
	bool isInTable(string label);
	void addSymbol(string label, int line);
	int getSymbolLine(string label);
	void getSymbolLineBin(string label, int *lineBinary);
};

/*Function for checking if a symbol is stored in the symbolTable
	label - the label of the symbol to search for
*/
bool symbolTable::isInTable(string label)
{
	for(Symbol &symbol : symbolTable)
	{
		if(symbol.getLabel() == label)
		{
			return true;
		}
	}

	return false;
}

/*Function for adding a symbol to the symbolTable
	label - the label of the symbol to be added
	line - the line of the symbol to be added
*/
void symbolTable::addSymbol(string label, int line)
{
	if(!symbolTable::isInTable(label))
	{
		Symbol symbol;
		symbol.assign(label, line);
		symbolTable.push_back(symbol);
	}
}

/*Function for returning a symbol's line for a symbol stored in the symbolTable
	label - the label of the symbol stored in the symbolTable
*/
int symbolTable::getSymbolLine(string label)
{
	for(Symbol &symbol : symbolTable)
	{
		if(symbol.getLabel() == label)
		{
			return symbol.getLine();
		}
	}

	//if no symbol with the argument label exists in symbolTable
	return 0;
}

/*Function for converting a symbol's line to binary for a symbol stored in the symbolTable
	label - the label of the symbol to be converted
	*lineBinary	- the array to store the line's binary conversion in
	arrayLength	- the length of the *lineBinary array
*/
void symbolTable::getSymbolLineBin(string label, int *lineBinary, int arrayLength)
{
	for(Symbol &symbol : symbolTable)
	{
		if(symbol.getLabel() == label)
		{
			BinaryConversion::toBinary(symbol.getLine(), lineBinary, arrayLength);
			return;
		}
	}
}

#endif