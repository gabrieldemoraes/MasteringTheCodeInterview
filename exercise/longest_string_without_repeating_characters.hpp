#ifndef LONGEST_STRING_WITHOUT_REPEATING_CHARACTERS_HPP
#define LONGEST_STRING_WITHOUT_REPEATING_CHARACTERS_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <map>

int couting_largest_strings(std::string &s)
{
    int tamanho = 0, p = 0;
    std::string aux;
    if(s.size() <=1 ) return s.size(); 
    while(p < s.size())
    {
        for(int i = p; i < s.size(); ++i)
        {
            if((aux.empty()) || (!aux.empty() && aux.find(s[i]) == std::string::npos))            
                aux+= s[i];
            else if(aux.find(s[i]) != std::string::npos)
            {
                tamanho = std::max(tamanho, int(aux.size()));
                aux.clear();
                break;
            }
        }
        ++p;
    }
    return tamanho;
}

int counting_largest_string_sliding_window(std::string &s)
{
    if(s.size() <=1 ) return s.size(); 
    std::map<char, int> charMap;
    std::map<char, int>::iterator it;

    int longest = 0, current = 0, inicio = 0;

    for(int i= 0; i < s.size(); ++i)
    {   
        it = charMap.find(s[i]);
        if(it != charMap.end() && it->second < inicio)
        {
            ++current;
            it->second = i;
        }
        else if(it != charMap.end() && it->second >= inicio)
        {
            if(current > longest) longest = current;
            inicio = it->second + 1;
            if(i == inicio) current = (i - inicio);
            else current = (i - inicio) + 1;
            if(current == 0) ++current;
            it->second = i;
        }
        else
        {
            ++current;
            char c = s[i];
            charMap.insert(std::pair<char, int>(c, i));
        }
    }
    if(current > longest ) return current;
    return longest;
}


int counting_largest_string_final(std::string &s)
{
    if(s.length() <= 1) return s.length();

    std::map<char, int> seenChars;
    int left = 0, longest = 0;

    for (int right = 0; right < s.length(); ++right)
    {
        char currentChar = s[right];
        char prevSeenChar = seenChars[currentChar];

        if(prevSeenChar >= left) left = prevSeenChar + 1;
        
        seenChars[currentChar] = right;

        longest = std::max(longest, right - left + 1);
    }

    return longest;
}

#endif