#include "lexicon.hpp"

Lexicon::Lexicon()
{}

int Lexicon::analyzer(std::string input)
{
	//check if its a number 
	if (isdigit(input[0]))
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				return ERROR;
			}
			
		}
		return NUM;
	}
}