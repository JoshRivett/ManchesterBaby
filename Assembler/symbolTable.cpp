/* 
  Name: Nicole Orr
  Matric number: 170010591
  Module code: AC21009
*/

#include "symbolTable.h"

/*Function for checking if a symbol is stored in the symbolTable
	label - the label of the symbol to search for
*/
bool SymbolTable::isInTable(string label)
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
void SymbolTable::addSymbol(string label, int line)
{
	if(!isInTable(label))
	{
		Symbol symbol;
		symbol.assign(label, line);
		symbolTable.push_back(symbol);
	}
}

/*Function for returning a symbol's line for a symbol stored in the symbolTable
	label - the label of the symbol stored in the symbolTable
*/
int SymbolTable::getSymbolLine(string label)
{
	for(Symbol &symbol : symbolTable)
	{
		if(symbol.getLabel() == label)
		{
			return symbol.getLine();
		}
	}

	//if no symbol with the argument label exists in symbolTable
	return -1;
}

/*Function for converting a symbol's line to binary for a symbol stored in the symbolTable
	label - the label of the symbol to be converted
	*lineBinary	- the array to store the line's binary conversion in
	arrayLength	- the length of the *lineBinary array
*/
void SymbolTable::getSymbolLineBin(string label, int *lineBinary, int arrayLength)
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