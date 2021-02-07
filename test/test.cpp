#define CATCH_CONFIG_MAIN

#include <sstream>

#include <cstdlib>

#include "catch/catch.hpp"
#include "../parser.hpp"
#include "../fileStream.hpp"
#include "../lexicon.hpp"

#define NUM 100
#define VAR 200 
#define ID 300
#define ERROR -1

TEST_CASE("FileStream")
{
    //Takes in the file and parses the input with parser 
    std::vector<std::string> code;
    FileStream fileStream("a1", code);
    
    //Amount of lines in the code 
    REQUIRE(code.size() == 6);
    REQUIRE(code.size() != 0);

    /* Getting correct lines and output within vector 
    for (int i = 0; i < code.size(); i++)
    {
        std::cout << "Line: " << i << " " << code.at(i) << "\n";
    }
    */

}

TEST_CASE("Parser")
{
    //Work on taking in input through strings and making sure they're parsed correctly char by char 
    
    //Takes in the file and parses the input with parser 
    std::vector<std::string> code;
    FileStream fileStream("a1", code);

    //Amount of lines in the code 
    REQUIRE(code.size() == 6);

    Parser parser(code);
    
    REQUIRE(parser.isComment("~this is a comment"));
    REQUIRE(!parser.isComment("this is NOT a comment"));

    REQUIRE(parser.isBegin("begin"));
    REQUIRE(!parser.isBegin("Begin"));



}

TEST_CASE("Lexicon")
{
    //checks the token to see what it is and return back to parser
    Lexicon lexicon;
   
    //Checking for correct number input syntax
    REQUIRE(lexicon.analyzer("100") == NUM);
    REQUIRE(lexicon.analyzer("1a0a") == ERROR);

    //REQUIRE(lexicon.analyzer("a_") == VAR);
    //REQUIRE(lexicon.analyzer("=") == ID);

   // REQUIRE();
}
