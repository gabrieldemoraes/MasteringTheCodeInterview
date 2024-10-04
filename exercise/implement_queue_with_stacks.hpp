#ifndef IMPLEMENT_QUEUE_WITH_STACKS
#define IMPLEMENT_QUEUE_WITH_STACKS

#include <stack>
#include <iostream>

void enqueue(std::stack<int> &s, int a)
{
    s.push(a);
}

int peek(std::stack<int> s)
{
    int i;
    for(i = 0; i < s.size() + 1; ++i)
    {
        s.pop();
    }

    std::cout <<s.top() << std::endl;

    return s.top();
}

bool isEmpty(std::stack<int> &s)
{
    if(s.size() == 0) return true;

    return false;
}

void dequeue(std::stack<int>& s)
{
    std::stack<int> iter;
    auto tamanho = s.size();

    for(int i = 0; i < tamanho -1; ++i)
    {
        iter.push(s.top());
        s.pop();
    }

    s.pop();
    for(int i = 0; i < tamanho - 1; ++i)
    {
        s.push(iter.top());
        iter.pop();
    }
}

//Course solution
/*
class QueueWithStacks
{
public:
    std::stack<int> in;
    std::stack<int> out;

    enqueue(int value)
    {
        in.push(value);
    }

    dequeue()
    {
        if(out.size() == 0)
        {
            while(in.size())
            {
                out.push(in.pop());
            }
        }
        return out.pop();
    }

    peek()
    {
        uf(out.size() == 0)
        {
            while(in.size())
            {
                out.push(in.pop());
            }
        }
        return out[out.size() - 1];
    }

    empty()
    {
        return in.size() == 0 && out.size() == 0; 
    }

}
*/

#endif 