//g++ -O3 valid_parentheses.cpp -o valid_parentheses.exe

#include "valid_parentheses.hpp"

int main()
{
    //std::string sequence = "{([]"; false
    //std::string sequence = ""; true
    std::string sequence = ")))"; 

    auto response = validParentheses(sequence);

    if(response) std::cout << "true" << std::endl;

    else std::cout << "false" << std::endl;

    return 0;
}