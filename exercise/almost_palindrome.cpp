//g++ -O3 almost_palindrome.cpp -o almost_palindrome.exe

#include "almost_palindrome.hpp"

int main()
{
    //EXAMPLE 1: TRUE
    //std::string s = "A man, a plan, a canal: Panama";
    //EXAMPLE 2: TRUE
    //std::string s = "raceacar";
    //EXAMPLE 3: TRUE
    //std::string s = "abccdba";
    //EXAMPLE 4: FALSE
    //std::string s = "abcdefdaba";
    //EXAMPLE 5: TRUE
    //std::string s = "";
    //EXAMPLE 6: TRUE
    //std::string s = "a";
    //EXAMPLE 7: TRUE
    std::string s = "ab";
    auto only_alpha = removing_not_alphanumeric(s);

    auto result = almost_palindrome(only_alpha);

    std::cout << result << std::endl;

    return 0;
}