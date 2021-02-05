#define CATCH_CONFIG_MAIN

#include <sstream>

#include <cstdlib>

#include "catch/catch.hpp"
#include "../parser.hpp"
#include "../fileStream.hpp"

TEST_CASE("FileStream")
{
    //Takes in the file and parses the input with parser 
    std::vector<std::string> code;
    FileStream fileStream("a1", code);
}

TEST_CASE("Parser")
{
    //Work on taking in input through strings and making sure they're parsed correctly char by char 
    REQUIRE(true);
}
/*
TEST_CASE("Lexicon")
{
    REQUIRE();
}
*/