//g++ -O3 validate_binary_search_tree.cpp -o validate_binary_search_tree.exe

#include "validate_binary_search_tree.hpp"
#include <iostream>

int main()
{

    Node node1;
    node1.value = 12;
    Node node2;
    node2.value = 7;
    Node node3;
    node3.value = 18;
    Node node4;
    node4.value = 5;
    Node node5;
    node5.value = 9;
    Node node6;
    node6.value = 16;
    Node node7;
    node7.value = 25;
    Node node8;
    node8.value = 8;
    Node node9;
    node9.value = 17;

    node1.left = &node2;
    node1.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node5.left = &node8;

    node3.left = &node6;
    node3.right = &node7;

    node6.right = &node9;

    if(is_valid_bst(&node1))
        std::cout << "Is a valid BST" << std::endl;



    return 0;
}