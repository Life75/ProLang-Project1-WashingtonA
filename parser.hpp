#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <vector>

#define NUM 100
#define ID 200 
#define EQ 64
#define OP 65
#define LEFT_PAR 40
#define RIGHT_PAR 41
#define ERROR -1

class Parser {

private:
    bool beginExe = false;
    int beginLine = 0;
    bool endExe = false;

public:
    Parser(std::vector<std::string> code);
    std::vector<int> statementParser(std::vector<std::string> code);
    bool isComment(std::string input);
    bool isBegin(std::string input, int beginLine);
    bool isEnd(std::string input, int endLine);

    //void syntaxChecker(std::string input);


//Need to parse statements based on semicolons not just lines t
};
#endif