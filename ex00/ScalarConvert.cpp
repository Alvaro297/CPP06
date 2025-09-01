#include "ScalarConvert.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>


int specialCasesSuport(const std::string& literal)
{
	if (literal == "nanf" || literal == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return 1;
	}

	if (literal == "inff" || literal == "inf" || literal == "+inff" || literal == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return 1;
	}

	if (literal == "-inff" || literal == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return 1;
	}
	return 0;
}

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

	if(typeInt < 0 || typeInt > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(typeInt))
		std::cout << "Is non printeable" << std::endl;
	else
		std::cout << "char: '" << typeChar << "'" << std::endl;
	std::cout << "int: " << typeInt << std::endl;
	std::cout << "float: " << typeFloat << ".0f" << std::endl;
	std::cout << "double: " << typeDouble << ".0" << std::endl;
}

void intType(const std::string& literal)
{
	int typeInt;
	char typeChar;
	float typeFloat;
	double typeDouble;

	typeInt = std::atol(literal.c_str());
	typeChar = static_cast<char>(typeInt);
	typeFloat = static_cast<float>(typeInt);
	typeDouble = static_cast<double>(typeInt);

	if(typeInt < 0 || typeInt > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(typeInt))
		std::cout << "Is non printeable" << std::endl;
	else
		std::cout << "char: '" << typeChar << "'" << std::endl;
	std::cout << "int: " << typeInt << std::endl;
	std::cout << "float: " << typeFloat << ".0f" << std::endl;
	std::cout << "double: " << typeDouble << ".0" << std::endl;
}

void floatType(const std::string& literal)
{
	float typeFloat;
	char typeChar;
	int typeInt;
	double typeDouble;
	double fracType;
	double partInt;

	if (specialCasesSuport(literal))
		return;

	typeFloat = static_cast<float>(std::atof(literal.c_str()));
	typeInt = static_cast<int>(typeFloat);
	typeChar = static_cast<char>(typeInt);
	typeDouble = static_cast<double>(typeFloat);
	fracType = std::modf(typeDouble, &partInt);

	if(typeInt < 0 || typeInt > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(typeInt))
		std::cout << "Is non printeable" << std::endl;
	else
		std::cout << "char: '" << typeChar << "'" << std::endl;
	std::cout << "int: " << typeInt << std::endl;
	if (fracType == 0)
	{
		std::cout << "float: " << typeFloat << ".0f" << std::endl;
		std::cout << "double: " << typeDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << typeFloat << "f" << std::endl;
		std::cout << "double: " << typeDouble << std::endl;
	}
}

void doubleType(const std::string& literal)
{
	double typeDouble;
	char typeChar;
	int typeInt;
	float typeFloat;
	double fracType;
	double partInt;

	if (specialCasesSuport(literal))
		return;

	typeDouble = std::atof(literal.c_str());
	typeInt = static_cast<int>(typeDouble);
	typeChar = static_cast<char>(typeInt);
	typeFloat = static_cast<float>(typeDouble);
	fracType = std::modf(typeDouble, &partInt);

	if(typeInt < 0 || typeInt > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(typeInt))
		std::cout << "Is non printeable" << std::endl;
	else
		std::cout << "char: '" << typeChar << "'" << std::endl;
	if (fracType == 0)
	{
		std::cout << "float: " << typeFloat << ".0f" << std::endl;
		std::cout << "double: " << typeDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << typeFloat << "f" << std::endl;
		std::cout << "double: " << typeDouble << std::endl;
	}
	std::cout << "int: " << typeInt << std::endl;
}

void invalidType()
{
	std::cerr << "Error: invalid literal type" << std::endl;
}

int checkSpecialCases(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff" || literal == "inf")
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
	if (i == 1 && !isdigit(literal[0]))
		return CHAR;
	if (literal[--i] == 'f')
			flagFloat = true;
	if (literal[i] == 'f')
		i--;
	while (i > 0)
	{
		if (isdigit(literal[i]) || literal[i] == '.'
			|| (i == 0 && (literal[i] == '-' || literal[i] == '+')))
		{
			if (literal[i] == '.')
				flagBullet = true;
		}
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
			invalidType();
			break;
		default:
			break;
	}
}