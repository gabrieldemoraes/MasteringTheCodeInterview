//g++ -O3 longest_string_without_repeating_characters.cpp -o longest_string_without_repeating_characters.exe

#include "longest_string_without_repeating_characters.hpp"
#include <iostream>
#include <iterator>

int main()
{
    
    //std::string a = "abccabb";

    //std::string a = "ccccccccccc";

    //std::string a = "";

    //std::string a = "abcbda";
    
    //std::string a = "abcbad";
    
    //std::string a = " ";

    //std::string a = "abcabcbb";

    std::string a = "aab";

    auto tamanho = couting_largest_strings(a);

    std::cout << "Antigo:" << tamanho << std::endl;


    auto size = counting_largest_string_final(a);

    std::cout << "Novo:" << size << std::endl;


    return 0;
}