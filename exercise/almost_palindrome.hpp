#ifndef ALMOST_PALINDROME
#define ALMOST_PALINDROME

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

bool is_palindrome(std::string s)
{
    int i = 0, j = s.size() - 1; 
    while(i < j)
    {
        if(std::tolower(s[i] != std::tolower(s[j])))
        {
            return false;
        }
        ++i;
        --j;
    }

    return true;
}

//Course solution is commented in the almost_palindrome
bool valid_sub_palindrome(std::string s, int left, int right)
{
    while(left < right)
    {
        if(s[left] != s[right])
            return false;
        ++left;
        --right;
    }
    return true;
}

bool almost_palindrome(std::string s)
{
    int i = 0, j = s.size() -1;
    std::string string1, string2;
    while(i < j)
    {
        if(std::tolower(s[i]) != std::tolower(s[j])){
            string1 = s;
            string1.erase(i, 1);

            string2 = s;
            string2.erase(j, 1);
            break;
            //return valid_sub_palindrome(s, i + 1, j) || return valid_sub_palindrome(s, i, j - 1);
        }
        ++i;
        --j;
    }
    // return true
    bool isPalindrome = is_palindrome(string1);
    
    if(isPalindrome == false){
        return (is_palindrome(string2));  
    }
    else return true;
}

#endif