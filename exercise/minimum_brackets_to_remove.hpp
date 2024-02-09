#ifndef MINIMUM_BRACKETS_TO_REMOVE
#define MINIMUM_BRACKETS_TO_REMOVE

#include<iostream>
#include<string>
#include<stack>

std::string minimum_brackets_removed(std::string &entrance)
{
    std::stack<char> stack;
    int control = 0;
    int i = entrance.length()-1;
    while(i >= 0)
    {
        if(entrance[i] == '(' && control == 0)
        {
            --i;
            continue;
        }
        if(entrance[i] == '(' && control > 0)
        {
            --control;
        }
    
        if(entrance[i] == ')' && control > 0)
        {   
            --i;
            continue;
        }
        if(entrance[i] == ')' && control == 0)
        {
            ++control;
        }    
        stack.push(entrance[i]);
        --i;
    }

    std::string result;
    i = 0;
    int size = stack.size();
    while(i != size)
    {
        if(stack.top() == ')' && control > 0)
        {
            --control;
            stack.pop();
            ++i;
            continue;
        }
        result += stack.top();
        stack.pop();
        ++i;
    }
    return result;
}

#endif