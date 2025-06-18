#ifndef MINIMUM_BRACKETS_TO_REMOVE_HPP
#define MINIMUM_BRACKETS_TO_REMOVE_HPP

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

//Time: O(n)
//Space O(n)
std::string minimum_brackets_removed_course_solution(std::string &entrance)
{
    std::stack<int> stack;
    int position;

    for(int i = 0; i < entrance.length(); ++i)
    {
        if(entrance[i] == '(')
        {
            stack.push(i);
        }

        if(entrance[i] == ')' && !stack.empty())
        {
            stack.pop();
        }

        else if(entrance[i] == ')' && stack.empty())
            entrance.erase(i);
    }

    while(!stack.empty())
    {
        position = stack.top();
        entrance.erase(position);
        stack.pop();
    }

    return entrance;
}

#endif