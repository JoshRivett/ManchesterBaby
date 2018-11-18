/* 
  Name: Nicole Orr
  Matric number: 170010591
  Module code: AC21009
*/

#ifndef SYMBOL_CLASS
#define SYMBOL_CLASS

//Using the standard namespace.
using namespace std;

class Symbol
{
	string label; //the symbol's label
	int line; //the symbol's address

public:

	string getLabel() { return label; }
	int getLine() { return line; }

	void setLabel(string label) { 
		this->label = label;
	}

	void setLine(int line) { 
		this->line = line;
	}

	void assign(string label, int line)
	{
		this->label = label; 
		this->line = line;
	}
};

#endif