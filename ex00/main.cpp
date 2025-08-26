#include "ScalarConvert.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    std::string literal = argv[1];
    ScalarConvert::convert(literal);
    return 0;
}
