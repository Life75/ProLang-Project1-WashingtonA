#ifndef LEXICON_HPP_
#define LEXICON_HPP_

#include <iostream>
#include <vector>
#include <string>

#define NUM 100
#define ID 200 
#define EQ 64
#define OP 65
#define LEFT_PAR 40
#define RIGHT_PAR 41
//#define 
#define ERROR -1


class Lexicon {
private:
	int lookAhead;

public:
	Lexicon();
	int analyzer(std::string input);
};
#endif