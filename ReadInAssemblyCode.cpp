#include<iostream>
#include<fstream>

using namespace std;

void readFile()
{
	std::string line;

	ifstream infile("./BabyTest1-Assembler.txt");

	if(!infile)
	{
		cout << "cannot open input file.\n" << endl;
	}

	ofstream convertedMC;
	
	convertedMC.open("ConvertedMachineCode.txt");
				
	while (std::getline(infile, line))//Up to here reads file
	{		

		std::string assemblyCode = line.substr(0, line.find(";"));

		assemblyCode += ";";
		//makes file easier to convert by removing comments on each line

		std::string machineCode = convertToBinary(assemblyCode);
		//converts assembly to machine code

		std::cout << machineCode << std::endl;
		//prints machine code into console

		convertedMC << machineCode << endl;
		//writes machine code into file to later be run by hardware simulator

	}
	convertedMC.close();

			
}

int main()
{
	readFile();	
}