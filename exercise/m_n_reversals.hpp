#ifndef M_N_REVERSALS
#define M_N_REVERSALS

#include <iostream>

class Node
{
public:
    int value;
    Node *next;
};


void swap(Node *previousLeft, Node *left, Node *previousRight, Node *right)
{    
    Node *iter = right->next;
    if(left == previousRight)
    {
        if(!previousLeft)
        {
            previousLeft = left;
            left = right;
            left->next = previousLeft->next;
            previousRight->next = previousLeft;
            previousLeft->next = iter;
        }
        else
        {
            previousLeft->next = right;
            left->next = right->next;
            right->next = left;
        }
    }
    else
    {
        if(!previousLeft)
        {
            previousLeft = left;
            left = right;
            left->next = previousLeft->next;
            previousRight->next = previousLeft;
            previousLeft->next = iter;
        }
        else
        {
            previousLeft->next = right;
            right->next = left->next;            
            previousRight->next = left;
            left->next = iter;
            //std::cout << left->value << " || " << iter->value << std::endl;
        }
    }

}

Node* m_n_reversals(Node &head, int m, int n)
{
    Node *currentNode = &head;
    Node *previous = nullptr;
    Node *left = nullptr;
    Node *previousLeft = nullptr;
    Node *right = nullptr;
    Node *previousRight = nullptr;
    Node *alternativeReturn = nullptr;

    int position = 1;
    while(currentNode)
    {
        if(position == m )
        {       
            left = currentNode;
            if(previous) previousLeft = previous;
            if(position == 1) alternativeReturn = left;
        }
        if(position == n)
        {
            right = currentNode;
            previousRight = previous;
            if(m < n)
            {
                swap(previousLeft, left, previousRight, right); 
                position = m;
                ++m;
                --n;
                currentNode = right;

                if(alternativeReturn == left) alternativeReturn = right;
            } 
            else break;
        }  
        previous = currentNode;
        currentNode = currentNode->next;
        ++position;
    }
    if(alternativeReturn) return alternativeReturn;
    else return &head;
}

Node *m_n_reversals_course_solution(Node &head, int m, int n)
{
    int currentPosition = 1;
    Node *currentNode = &head;
    Node *start = nullptr;

    while(currentPosition <= m)
    {
        start = currentNode;
        currentNode = currentNode->next;
        ++currentPosition;   
    }
    Node *newList = nullptr;
    Node *tail = currentNode;   
    std::cout << currentPosition << std::endl;


    while(currentPosition >= m && currentPosition <= n)
    {
        Node *next = currentNode->next;
        currentNode->next = newList;
        newList = currentNode;
        currentNode = next;
        ++currentPosition;
    
    }
    start->next = newList;
    tail->next = currentNode;

    if(m > 1) return &head;
    else 
        return start;
}

#endif