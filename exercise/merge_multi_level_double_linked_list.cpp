//g++ -O3 merge_multi_level_double_linked_list.cpp -o merge_multi_level_double_linked_list.exe

#include "merge_multi_level_double_linked_list.hpp"
#include <iostream>

int main()
{

    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e; 
    ListNode f;
    ListNode g;
    ListNode h;
    ListNode i;
    ListNode j;
    ListNode k;
    ListNode l;
    ListNode m;
    ListNode n;
    ListNode o;

    a.value = 1;
    b.value = 2;
    c.value = 3;
    d.value = 4;
    e.value = 5;
    f.value = 6;
    g.value = 7;
    h.value = 8;
    i.value = 9;
    j.value = 10;
    k.value = 11;
    l.value = 12;
    m.value = 13;

    n.value = 14;
    o.value = 15;


    a.previous = nullptr;
    b.previous = &a;
    c.previous = &b;
    d.previous = &c;
    e.previous = &d;
    f.previous = &e;
    g.previous = &b;
    h.previous = &g;
    i.previous = &h;
    j.previous = &h;
    k.previous = &k;
    l.previous = &e;
    m.previous = &l;

    n.previous = &f;
    n.next = &o;
    o.previous = &n;
    o.next = nullptr;
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = nullptr;
    g.next = &h;
    h.next = &i;
    i.next = nullptr;
    j.next = &k;
    k.next = nullptr;
    l.next = &m;
    m.next = nullptr;

    b.child = &g;
    h.child = &j;
    e.child = &l;
    f.child = &n;

    mergeLists(a);

    ListNode *currentNode = &a;    

    while (currentNode)
    {
        std::cout << currentNode->value << std::endl;
        currentNode = currentNode->next;
    }

    return 0;
}
