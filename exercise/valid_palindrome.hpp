#ifndef VALID_PALINDROME_HPP
#define VALID_PALINDROME_HPP

#include <iostream>
#include <string>
#include <regex>

std::string removing_not_alphanumeric(std::string s)
{
    std::regex regex("[^a-zA-Z0-9]");
    

    std::string result;
    std::regex_replace (std::back_inserter(result), s.begin(), s.end(), regex, "");

    return result;
}

bool is_valid_palindrome_reverse(std::string s)
{
    int i = 0, j = s.size() -1;
    while(i < j)
    {
        if(std::tolower(s[i]) != std::tolower(s[j])) return false;
        ++i;
        --j;
    }
    return true;
}

bool is_valid_palindrome_start_in_the_middle(std::string s)
{
    int i = (s.size()/2) - 1;
    int j = (s.size()/2) + 1;

    while(i > 0 || j < s.size())
    {
        if(std::tolower(s[i]) != std::tolower(s[j])) return false;
        --i;
        ++j;
    }
    return true;
}

bool is_valid_palindrome_compare_reverse(std::string s)
{
    std::string reverse = s;

    std::reverse(reverse.begin(), reverse.end());

    for(int i = 0; i < s.size(); ++i)
    {
        if(std::tolower(s[i]) != std::tolower(reverse[i])) return false;
    }
    return true;
}

#endif