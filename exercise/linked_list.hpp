#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

class Node
{
public:
    int value;
    Node *next;
};

//Complexidade: O(n)
// Espaço: O(n)
Node *reverse(Node head)
{
    Node *currentNode = &head;
    Node *previous = nullptr;
    Node *n = new Node();
    while(currentNode)
    {
        if(!previous)
        {
            n->value = currentNode->value;
            n->next = nullptr;
        }
        n->value = currentNode->value;
        n->next = previous;
        previous = n;
        currentNode = currentNode->next;
    }
    return n;
}


//Complexidade: O(n)
// Espaço: O(1)
Node *copy_reverse(Node head)
{
    Node *currentNode = &head;
    Node *previous = nullptr;

    while(currentNode)
    {
        Node *next = currentNode->next;
        currentNode->next = previous;
        previous = currentNode;
        currentNode = next;
    }

    return previous;

}


#endif