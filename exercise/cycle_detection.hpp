#ifndef CYCLE_DETECTION
#define CYCLE_DETECTION

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode* next;
};


bool has_cycle(SinglyLinkedListNode* head) {
    if(!head || !head->next)
    {
        return false;
    }
    
    SinglyLinkedListNode* tortoise = head;
    SinglyLinkedListNode* hare = head ->next;
    
    while (hare && hare -> next) 
    {
        if (tortoise == hare) {
            return true;
        }
        tortoise = tortoise ->next;
        hare = hare ->next->next;
    }
    return false;
}

#endif