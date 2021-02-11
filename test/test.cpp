#define CATCH_CONFIG_MAIN

#include <sstream>

#include <cstdlib>

#include "catch/catch.hpp"
#include "../parser.hpp"
#include "../fileStream.hpp"
#include "../lexicon.hpp"

#define NUM 100
#define ID 200 
#define EQ 64
#define OP 65
#define LEFT_PAR 40
#define RIGHT_PAR 41
 
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

    //Checking for correct variable input syntax
    REQUIRE(lexicon.analyzer("abc2") == ID);
    REQUIRE(lexicon.analyzer("a_bc2") == ID);

    REQUIRE(lexicon.analyzer("a_") == ERROR);
    REQUIRE(lexicon.analyzer("_abc") == ERROR);
    REQUIRE(lexicon.analyzer("a__") == ERROR);

    //Checking for correct assignment operator 
    REQUIRE(lexicon.analyzer("=") == EQ);

    REQUIRE(lexicon.analyzer("*") == OP);
    REQUIRE(lexicon.analyzer("+") == OP);
    REQUIRE(lexicon.analyzer("-") == OP);

    REQUIRE(lexicon.analyzer("(") == LEFT_PAR);
    REQUIRE(lexicon.analyzer(")") == RIGHT_PAR);

    REQUIRE(lexicon.analyzer("!") == ERROR);

    REQUIRE(lexicon.analyzer("=dbs_") == ERROR);

   // REQUIRE();
}
