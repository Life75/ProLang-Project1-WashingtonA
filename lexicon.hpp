#ifndef LEXICON_HPP_
#define LEXICON_HPP_

#include <iostream>
#include <vector>
#include <string>

#define NUM 100
#define VAR 200 
#define ID 300
#define ERROR -1


class Lexicon {
private:
	int lookAhead;

public:
	Lexicon();
	int analyzer(std::string input);
};
#endif