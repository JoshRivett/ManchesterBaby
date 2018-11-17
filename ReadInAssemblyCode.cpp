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
				
	while (std::getline(infile, line))
	{		

		std::string binaryConvert = line.substr(0, line.find(";"));

		binaryConvert += ";";

		std::cout << binaryConvert << std::endl;

		convertedMC << binaryConvert << endl;

	}
	convertedMC.close();

			
}

int main()
{
	readFile();	
}