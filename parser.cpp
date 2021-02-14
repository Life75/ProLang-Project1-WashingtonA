#include "parser.hpp"



Parser::Parser(std::vector<std::string> code)
{
    //Handle comments, begin, {code} , end for each line given by vector 
    for (int i = 0; i < code.size(); i++)
    {
        if (!isComment(code.at(i)))
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

std::vector<int> Parser::statementParser(std::vector<std::string> code)
{
    std::vector<int> statements;
    //parsing the data by semicolons 
    for (int i = beginLine; i < code.size(); i++)
    {
       // std::cout << beginLine << std::endl;
        std::cout << code.at(1) << std::endl;;
        //std::cout << "hello";
    }
    
        return statements;
}
/*
void Parse::syntaxChecker(std::string input)
{

}
*/