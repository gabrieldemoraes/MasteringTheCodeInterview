#ifndef MERGE_MULTI_LEVEL_DOUBLE_LINKED_LIST
#define MERGE_MULTI_LEVEL_DOUBLE_LINKED_LIST

#include <iostream>

class ListNode
{
public:
    int value;
    ListNode *previous;
    ListNode *next;
    ListNode *child = nullptr;
};

// time: O(n)
// space: O(1)
void mergeLists(ListNode &head)
{
    ListNode *currentNode = &head;
    while(currentNode != nullptr)
    {
        if(currentNode->child != nullptr)
        {
            ListNode *childNode = currentNode->child;
            while (childNode->next != nullptr)
                childNode = childNode->next;

            //Step 1
            childNode->next = currentNode->next;
            if(childNode->next != nullptr)
                currentNode->next->previous = childNode;
            //Step 2
            currentNode->next = currentNode->child;
            currentNode->child->previous = currentNode;
            //Step 3
            currentNode->child = nullptr;
        }
        currentNode = currentNode->next;
    }
}

#endif