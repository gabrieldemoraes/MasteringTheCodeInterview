#ifndef LEVEL_ORDER_OF_BINARY_SEARCH_TREE_HPP
#define LEVEL_ORDER_OF_BINARY_SEARCH_TREE_HPP

#include <queue>
#include <iostream>

struct Node
{
    int value;
    Node *right = nullptr;
    Node *left = nullptr;
};

void level_order_of_binary_tree(Node *n)
{
    
    std::queue<Node*> q;
    std::vector<int> result;
    q.push(n);
    int level = 1;
    while(!q.empty())
    {
        auto current = q.front();
        result.push_back(current->value);

        const int lenght = q.size();

        q.pop();

        std::cout << current->value << std::endl;

        for(auto i = 0; i < lenght; ++i)
        {
            if(current->left) 
                q.push((current->left));

            if(current->right) 
                q.push((current->right));

        }
        ++level;
    }
}

#endif