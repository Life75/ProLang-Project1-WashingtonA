#include "lexicon.hpp"

Lexicon::Lexicon()
{}
//checks the value and proper syntax for the value or will return an error 
int Lexicon::analyzer(std::string input)
{
	clearLookAhead();
//EQ
	if (input[0] == '=')
	{
		if (input.length() > 1)
			return ERROR;
		else 
		{
		lookAhead.push_back(ID);
		lookAhead.push_back(NUM);
		return EQ;
		}
	
	}
//OPERATORS OP
	if (input[0] == 42 || input[0] == 43 || input[0] == 45 || input[0] == 47)
	{
		if (input.length() > 1)
			return ERROR;
		else
		{
			lookAhead.push_back(ID);
			lookAhead.push_back(NUM);
			lookAhead.push_back(LEFT_PAR);
			return OP;
		}
	}

	if (input[0] == LEFT_PAR) 
	{
		lookAhead.push_back(ID);
		lookAhead.push_back(NUM);
		lookAhead.push_back(RIGHT_PAR);
		lookAhead.push_back(LEFT_PAR);
		return LEFT_PAR;
	}

	if (input[0] == RIGHT_PAR) 
	{
		lookAhead.push_back(ID);
		lookAhead.push_back(NUM);
		lookAhead.push_back(RIGHT_PAR);
		lookAhead.push_back(LEFT_PAR);
		return RIGHT_PAR;
	} 


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
		lookAhead.push_back(OP);
		//lookAhead.push_back(LEFT_PAR);
		//lookAhead.push_back(RIGHT_PAR);
		return NUM;
	}

	//check if its an ID 
	if (!isdigit(input[0]) && (input[0] >= 64 && input[0] <= 122) )
	{
		//1. checks for consecutive underscores within var, 2. then checks if it starts or ends with an underscore, 3. or if it starts with a number 
		for (int i = 0; i < input.length(); i++)
		{
			if (i != 0)
			{
				if (input[i] == '_' && input[i - 1] == '_')
				{
					return ERROR; //1
				}
			}
			else
			{
				if (input[i] == '_' || isdigit(input[i])) return ERROR; //2 & 3
			}

			if (i == input.length() - 1)
			{
				if (input[i] == '_') return ERROR;
			}

		}

		lookAhead.push_back(EQ);
		lookAhead.push_back(OP);
		//lookAhead.push_back(LEFT_PAR);
		lookAhead.push_back(RIGHT_PAR);
		return ID;
	}

	

	return ERROR;

}

std::vector<int> Lexicon::getLookAhead()
{
	return lookAhead;
}

void Lexicon::clearLookAhead()
{
	lookAhead.clear();
}
