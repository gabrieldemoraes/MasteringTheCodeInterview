#ifndef NUMBER_OF_NODES_IN_COMPLETE_TREE_HPP
#define NUMBER_OF_NODES_IN_COMPLETE_TREE_HPP

#include <math.h>
#include <iostream>
#include <cstddef>

struct Node
{
    int value;
    Node *right = nullptr;
    Node *left = nullptr;
};

int get_tree_heights(Node *n)
{
    int height = 0;
    while(n->left != nullptr)
    {
        ++height;
        n = n->left;
    }
    return height;
}

bool node_exists(int indexToFind, int height, Node *n)
{
    int left = 0, right = (pow(2, height) -1), count = 0;
    
    while(count < height)
    {
        auto midOfNode = std::ceil((left+right)/2.0);

        if(indexToFind >= midOfNode)
        {
            n = n->right;
            left = midOfNode;
        }
        else
        {
            n = n->left;
            right = midOfNode - 1;
        }
        ++count;
    }
    return (n != nullptr);
}

int count_nodes(Node * n)
{
    if(!n) return 0;

    int height = get_tree_heights(n);

    if(height == 0) return 1;

    auto upperCount = pow(2, height) - 1;
    int left = 0, right = upperCount;

    while(left < right)
    {
        auto indexToFind = ceil((left+right)/2.0);

        if(node_exists(indexToFind, height, n))
            left = indexToFind;
        else
            right = indexToFind - 1;
    }
    return upperCount + left + 1; //daria pra usar o right ao inves do left
}


class complete_binary_tree_counter final
{
    static std::size_t leftmost_lenght(Node *root) noexcept
    {
        std::size_t n{0};
        while(root)
        {
            ++n;
            root = root->left;
        }
        return n;
    }

    static std::size_t is_null_leaf(Node *root, std::size_t index, std::size_t height) noexcept
    {
        std::size_t mask = 1 << height;
        while(mask >>=1)
            root = (index & mask) ? root->right : root->left;
        return root == nullptr;
    }

public:    
    static std::size_t count(Node *root) noexcept
    {
        if(!root) return 0;

        std::size_t ll = leftmost_lenght(root);
        if(ll <= 1) return ll;
        std::size_t height = ll - 1, N = std::size_t(std::pow(std::size_t{2}, height));
        std::size_t left{1}, right{N-1}, mid{}, M{};
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(is_null_leaf(root, mid, height))
            {
                right = mid -1;
            }
            else{
                M = mid;
                left = mid + 1;
            }
            return N + M;
        }
    }
};

#endif

