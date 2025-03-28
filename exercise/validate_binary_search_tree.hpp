#ifndef VALIDATE_BINARY_SEARCH_TREE_HPP
#define VALIDATE_BINARY_SEARCH_TREE_HPP

#include <limits>

struct Node
{
    int value;
    Node *right = nullptr;
    Node *left = nullptr;
};

bool DFS(Node *n, int min, int max)
{
    if(n->value <= min || n->value >= max) return false;

    if(n->left)
    {
        if(!DFS(n->left, min, n->value)) return false;
    }

    if(n->right)
    {
        if(!DFS(n->right, n->value, max)) return false;
    }

    return true;
}

bool is_valid_bst(Node *n)
{
    if(!n) return true;
    
    //PRE-ORDER: NLR
    return DFS(n, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

#endif







