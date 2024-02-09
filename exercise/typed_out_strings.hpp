#ifndef TYPED_OUT_STRINGS
#define TYPED_OUT_STRINGS

#include <stack>
#include <string>
#include <vector>
#include <iostream>

std::string typed_out_strings_with_stack(std::string s)
{
    std::stack<char> inter;
    std::string result;
    std::string j;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '#' && !inter.empty())
            inter.pop();
        else inter.push(s[i]);
    }
    while(!inter.empty())
    {
        j = inter.top(); 
        result.insert(0, j);
        inter.pop();
    }
    return result;
}

std::string typed_out_strings(std::string s)
{
    std::string result;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '#' && !result.empty())
            result.pop_back();
        if(s[i] != '#') result.push_back(s[i]);
    }

    return result;
}

void typed_out_string_optimal_space(std::string &s)
{
    int right = s.size();
    int left = s.size() -1;
    while(right >= 0)
    {
        if((right >= 0 && left >= 0) && 
           (s[right] && s[left]) && 
           (s[right] == '#'  && s[left] != '#'))
        {
            s.erase(left, 2);
        }
        else if(right == 0 && s[right] == '#')
        {
            s.erase(right, 1);
        }
        else 
        {
            --left;
            --right;
        }
    }
}

bool typed_out_string_final(std::string &s, std::string &t)
{
    int p1 = s.size() - 1;
    int p2 = t.size() - 1;

    while(p1>=0 || p2 >= 0)
    {
       if(p1>0 && s[p1] && s[p1]== '#' || p2>=0 && t[p2] && t[p2]=='#')
        {
            if(p1>=0 && s[p1] && s[p1] == '#')
            {
                int backCount = 2;
                while(backCount > 0)
                {
                    --p1;
                    --backCount;
                    if(p1 >=0 && s[p1] && s[p1] =='#') backCount+=2;
                }
            }
            if(p2>=0 && t[p2] && t[p2] == '#')
            {
                int backCount = 2;
                while(backCount > 0)
                {
                    --p2;
                    --backCount;
                    if(p2 >= 0 && t[p2] && t[p2] == '#') backCount+=2;
                }
            }
        }
        else
        {
            if((s[p1] && t[p2]) && s[p1] != t[p2]) return false;
            else
            {
                --p1;
                --p2;
            }
        }
    }
    return true;
}

#endif