#ifndef RIGHT_SIDE_VIEW_OF_TREE_HPP
#define RIGHT_SIDE_VIEW_OF_TREE_HPP

#include <vector>
#include <queue>
#include <iostream>

struct Node
{
    int value;
    Node *right = nullptr;
    Node *left = nullptr;
};

std::vector<int> right_side_view_of_tree_bfs(Node *n)
{
    std::queue<Node*> q;
    std::vector<int> result;
    q.push(n);
    int level = 1;
    while(!q.empty())
    {
        const int lenght = q.size();
        Node *current;
        
        for(auto i = 0; i < lenght; ++i)
        {
            
            current = q.front();        

            std::cout << "current: " <<current->value << std::endl;

            q.pop();

            if(current->left) 
                q.push((current->left));

            if(current->right) 
                q.push((current->right));
                
        }
        result.push_back(current->value);
    }
    return result;
}

void right_side_view_of_tree_dfs(Node *n, int levelCheck, std::vector<int>& v)
{
    if(!n) return;
    
    if(levelCheck >= v.size())
        v.push_back(n->value);

    ++levelCheck; //putting like this in the call of functions, the result is wrong

    if(n->right) right_side_view_of_tree_dfs(n->right, levelCheck, v);
    if(n->left) right_side_view_of_tree_dfs(n->left, levelCheck, v);
}

#endif

