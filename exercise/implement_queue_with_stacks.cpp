//g++ -O3 implement_queue_with_stacks.cpp -o implement_queue_with_stacks.exe

#include "implement_queue_with_stacks.hpp"

int main()
{
    std::stack<int> s;

    //if(isEmpty(s) == true ) std::cout << "esta vazio" << std::endl;

    s.push(5);
    s.push(8);
    s.push(7);
    s.push(9);

    //if(isEmpty(s) != true ) std::cout << "nao esta vazio" << std::endl;

    //enqueue(s, 1);

    dequeue(s);

    int tamanho = s.size();


    for(int i = 0; i < tamanho; ++i)
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}