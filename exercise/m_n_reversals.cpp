//g++ -g m_n_reversals.cpp -o m_n_reversals.exe
//g++ -O3 m_n_reversals.cpp -o m_n_reversals.exe

#include "m_n_reversals.hpp"

int main()
{

    Node a;
    Node b;
    Node c;
    Node d;
    Node e; 
    Node f;
    a.value = 1;
    b.value = 2;
    c.value = 3;
    d.value = 4;
    e.value = 5;
    f.value = 6;
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = nullptr;
    
    Node *result = m_n_reversals_course_solution(a, 2, 5);
    Node *currentNode = result;    

    while (currentNode)
    {
        std::cout << currentNode->value << std::endl;
        currentNode = currentNode->next;
    }
    

    return 0;
}