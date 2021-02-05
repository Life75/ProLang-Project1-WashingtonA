#include "fileStream.hpp"

 FileStream::FileStream(std::string fileName, std::vector<std::string> code)
{
	std::fstream file;
	fileName = fileName;
	file.open(fileName.c_str());
	std::string ch;
	int count= 0;
	
	
	while (!file.eof())
	{
		std::getline(file, ch);
		
		std::cout << ch << "\n";
		count++;
	}

	std::cout << count;
	/*
	while(file >> ch)
	{
		if (ch == "\n")
		{
			std::cout << "newline";
			lineCount++;

		}
		std::cout << ch << "\n"; 
	}
	*/
}