#include "parser.hpp"
#define NUM 100
#define VAR 200 
#define ID 300


Parser::Parser(std::vector<std::string> &code)
{
    
}

bool Parser::isComment(std::string input)
{
    if (input.at(0) == '~')
        return true;
    else
        return false;
}

bool Parser::isBegin(std::string input)
{
    if (input == "begin")
        return true;
    else
        return false;
}
/*
void Parse::syntaxChecker(std::string input)
{

}
*/
