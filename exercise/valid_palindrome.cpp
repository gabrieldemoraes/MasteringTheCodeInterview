//g++ -O3 valid_palindrome.cpp -o valid_palindrome.exe

#include "valid_palindrome.hpp"

int main()
{
    std::string s = "A man, a plan, a canal: Panama";

    auto only_alpha = removing_not_alphanumeric(s);

    auto response = is_valid_palindrome_compare_reverse(only_alpha);

    std::cout << response << std::endl;

    return 0;
}