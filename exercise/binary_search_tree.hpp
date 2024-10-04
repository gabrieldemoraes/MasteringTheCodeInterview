#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <queue>


struct Node
{
    int value;
    Node *right = nullptr;
    Node *left = nullptr;
};

std::size_t DFS(Node *n, unsigned int depth)
{
    if(!n) return depth;
    ++depth;
    return std::max(DFS(n->right, depth), DFS(n->left, depth));
}

/*
Node* BFS(Node *n)
{
    Node result;
    std::queue<Node> *q;
    q->push(*n);
    while(!q->empty())
    {
        result = q->front();
        q->pop();
        if(result.left) q->push(*(result.left));
        if(result.right) q->push(*(result.right));
    }

    return &result;
}
*/
#endif