//g++ -O3 linked_list.cpp -o linked_list.exe
#include "linked_list.hpp"

int main()
{
    Node a;
    Node b;
    Node c;
    Node d;
    Node e; 
    a.value = 1;
    b.value = 2;
    c.value = 3;
    d.value = 4;
    e.value = 5;
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;

    Node *result = reverse(a);

    std::cout << result->value << std::endl;

    return 0;
}