#ifndef VALID_PARENTHESES_HPP
#define VALID_PARENTHESES_HPP

#include <string>
#include <stack>
#include <iostream>
#include <map>

bool valid_parentheses(std::string &sequence)
{
    std::stack<char> parenteses;
    std::stack<char> colchetes;
    std::stack<char> chaves;

    if(sequence.empty()) return true;
    else
    {
        for(auto it: sequence)
        {
            if(it == '{') chaves.push(it);

            if(it == '[') colchetes.push(it);

            if(it == '(') parenteses.push(it);

            if(it == '}')
            {
                if(chaves.empty()) return false;
                chaves.pop();
            } 

            if(it == ']')
            {
                if(colchetes.empty()) return false;
                colchetes.pop();
            }

            if(it == ')')
            {
                if(parenteses.empty()) return false;
                parenteses.pop();
            }   
        }

        if(!chaves.empty() || !colchetes.empty() || !parenteses.empty())
        {
            return false;
        } 
        else true;
    }
}

//space = O(n)
// time = O(n)
bool valid_parentheses_course_solution(std::string &sequence)
{
    std::map<char,char> parentheses;
    parentheses.insert(std::pair<char,char>('[', ']'));
    parentheses.insert(std::pair<char,char>('(', ')'));
    parentheses.insert(std::pair<char,char>('{', '}'));

    if(sequence.empty()) return true;

    std::stack<char> stack;

    for(auto it: sequence)
    {
        if(parentheses[it]) stack.push(it);
        else
        {
            char leftBracket = stack.top();
            stack.pop();
            char correctBracket = parentheses[leftBracket];
            if(it != correctBracket) return false;
        }
    }
    if(stack.empty()) return true;
    return false;
}

#endif