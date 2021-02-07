#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <vector>
//
class Parser {

    private:

    public:
        Parser(std::vector<std::string> &code);
        bool isComment(std::string input);
        bool isBegin(std::string input);
        //void syntaxChecker(std::string input);

};
#endif