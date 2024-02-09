//g++ -O3 minimum_brackets_to_remove.cpp -o minimum_brackets_to_remove.exe

#include "minimum_brackets_to_remove.hpp"

int main()
{
    //TESTE 1
    //std::string testeCase = "a)b(((cd)";
    //TESTE2
    //std::string testeCase = "(ab(c)d";
    //TESTE 3
    std::string testeCase = "a)bc(d)";

    auto result = minimum_brackets_removed(testeCase);

    std::cout << result << std::endl;
    
    return 0;
}