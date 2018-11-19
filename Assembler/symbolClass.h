/*
	Names:			Christian Hegarty,	Naqash Nadeem,	Nicole Orr,	Josh Rivett,	Shaun Yap
	Matric Number: 	170025705			160010238		170010591	170005367		160006581
	Module Code: 	AC21009
	Team Number:	15
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