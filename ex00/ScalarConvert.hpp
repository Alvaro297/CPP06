#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <string>

enum LiteralType
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	INVALID = 4
};

class ScalarConvert {
public:
	static void convert(const std::string& literal);
};

#endif