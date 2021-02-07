#ifndef FILESTREAM_HPP_
#define FILESTREAM_HPP_

#include <iostream>
#include <fstream>
#include <vector>

class FileStream {
private:
	std::string fileName;
public:
	FileStream(std::string fileName, std::vector<std::string> &code);

};
#endif