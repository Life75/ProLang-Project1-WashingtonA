#include "parser.hpp"



Parser::Parser(std::vector<std::string> code)
{
    //Handle comments, begin, {code} , end for each line given by vector 
    for (int i = 0; i < code.size(); i++)
    {
        if (!isComment(code.at(i))) //handle for incase there is code after with an else statement 
        {
            isBegin(code.at(i), i);

            if (beginExe)
            {
                break;
                //Break the lines into statements going through each character until a semicolon is found 
                
                //Break those statements into expressions 
            }
        }
    }
    statementParser(code);
}

bool Parser::isComment(std::string input)
{
    if (input.length() > 0)
    {
        if (input.at(0) == '~')
            return true;
        else
            return false;
    }

}

bool Parser::isBegin(std::string input, int beginLine)
{
    if (input.length() > 0)
    {
        if (input == "begin")
        {
            if (!beginExe)
            {
                this->beginLine = beginLine + 1;//where the code section begins 
                beginExe = true;
            }
            return true;
        }
        else
            return false;
    }

}

bool Parser::isEnd(std::string input, int endLine)
{
    if (input.length() > 0)
    {
        if (input == "end.")
        {
            if (!endExe)
            {
                this->endLine = endLine; //end line for code 
                endExe = true;
            }
            return true;
        }
        else return false;
    }
}

std::vector<int> Parser::statementParser(std::vector<std::string> code)
{
    std::vector<int> statements;
    //parsing the data by semicolons 
    for (int i = beginLine; i < code.size(); i++)
    {
       // std::cout << beginLine << std::endl;
        //finds the semicolon within line 
        char ch;
        std::stack<std::string> holder; //incase a line doesn't have semicolon hold and until it gets to the semicolon pop all the contents out to that string and form a single statement 
        for (int j = 0; j < code.at(i).length(); j++)
        {
            if(code.at(i) 
            ch = code.at(i).at(j);
            

        }
        //std::cout << "hello";
    }
    
        return statements;
}


/*
void Parse::syntaxChecker(std::string input)
{

}
*/