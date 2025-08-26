void charType(const std::string& literal)
{
	char typeChar;
	int typeInt;
	double typeDouble;
	float typeFloat;

	typeChar = literal[0];
	typeInt = static_cast<int>(typeChar);
	typeFloat = static_cast<float>(typeChar);
	typeDouble = static_cast<double>(typeChar);

	std::cout << "char: '" << typeChar << "'" << std::endl;
	std::cout << "int: " << typeInt << std::endl;
	std::cout << "float: " << typeFloat << "f" << std::endl;
	std::cout << "double: " << typeDouble << std::endl;
}

void intType(const std::string& literal)
{
	int typeInt;
	char typeChar;
	float typeFloat;
	double typeDouble;

	typeInt = std::stoi(literal);
	typeChar = static_cast<char>(typeInt);
	typeFloat = static_cast<float>(typeInt);
	typeDouble = static_cast<double>(typeInt);

	std::cout << "char: '" << typeChar << "'" << std::endl;
	std::cout << "int: " << typeInt << std::endl;
	std::cout << "float: " << typeFloat << "f" << std::endl;
	std::cout << "double: " << typeDouble << std::endl;
}

void floatType(const std::string& literal)
{
	float typeFloat;
	char typeChar;
	int typeInt;
	double typeDouble;

	typeFloat = std::stof(literal);
	typeChar = static_cast<char>(typeFloat);
	typeInt = static_cast<int>(typeFloat);
	typeDouble = static_cast<double>(typeFloat);

	std::cout << "char: '" << typeChar << "'" << std::endl;
	std::cout << "int: " << typeInt << std::endl;
	std::cout << "float: " << typeFloat << "f" << std::endl;
	std::cout << "double: " << typeDouble << std::endl;
}

void doubleType(const std::string& literal)
{
	double typeDouble;
	char typeChar;
	int typeInt;
	float typeFloat;

	typeDouble = std::stod(literal);
	typeChar = static_cast<char>(typeDouble);
	typeInt = static_cast<int>(typeDouble);
	typeFloat = static_cast<float>(typeDouble);

	std::cout << "char: '" << typeChar << "'" << std::endl;
	std::cout << "int: " << typeInt << std::endl;
	std::cout << "float: " << typeFloat << "f" << std::endl;
	std::cout << "double: " << typeDouble << std::endl;
}

void invalidType(const std::string& literal)
{
	std::cerr << "Error: invalid literal type" << std::endl;
}
#include <iostream>
#include "ScalarConvert.hpp"

int checkSpecialCases(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
 		return FLOAT;
 	else if (literal == "nan" || literal == "+inf" || literal == "-inf")
 		return DOUBLE;
 	else if (literal.length() == 1 && !isdigit(literal[0]))
 		return CHAR;
 	return INVALID;
}

int knowData(const std::string& literal)
{
	int	i;
	int	special;
	bool flagFloat;
	bool flagBullet;


	flagBullet = false;
	flagFloat = false;
	i = literal.length();
	special = checkSpecialCases(literal);
	if (special != INVALID)
		return special;
	if (i == 1 && !isdigit(literal[i]))
		return CHAR;
	if (literal[--i] == 'f')
			flagFloat = true;
	while (i > 0)
	{
		if (isdigit(literal[i]) || literal[i] == '.'
			|| (i == 0 && (literal[i] == '-' || literal[i] == '+')))
			if (literal[i] == '.')
				flagBullet = true;
		else
			return INVALID;
		i--;
	}
	if (flagFloat && flagBullet)
		return FLOAT;
	if (flagBullet)
		return DOUBLE;
	if (!flagBullet && !flagFloat)
		return INT;
	return INVALID;
}

void ScalarConvert::convert(const std::string& literal)
{
	int		typeOfData;

	typeOfData = knowData(literal);
	switch (typeOfData)
	{
		case CHAR:
			charType(literal);
			break;
		case INT:
			intType(literal);
			break;
		case FLOAT:
			floatType(literal);
			break;
		case DOUBLE:
			doubleType(literal);
			break;
		case INVALID:
			invalidType(literal);
			break;
		default:
			break;
	}
}