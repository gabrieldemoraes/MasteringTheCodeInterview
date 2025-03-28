//g++ -O3 number_of_nodes_in_complete_tree.cpp -o number_of_nodes_in_complete_tree.exe


#include "number_of_nodes_in_complete_tree.hpp"
#include <iostream>

int main()
{

    Node node1;
    node1.value = 1;
    Node node2;
    node2.value = 2;
    Node node3;
    node3.value = 3;
    Node node4;
    node4.value = 4;
    Node node5;
    node5.value = 5;
    Node node6;
    node6.value = 6;
    Node node7;
    node7.value = 7;
    Node node8;
    node8.value = 8;
    Node node9;
    node9.value = 9;
    Node node10;
    node10.value = 10;
    Node node11;
    node11.value = 11;
    Node node12;
    node12.value = 12;

    node1.left = &node2;
    node1.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    node3.left = &node6;
    node3.right = &node7;

    node4.left = &node8;
    node4.right = &node9;

    node5.left = &node10;
    node5.right = &node11;

    node6.left = &node12;

    count_nodes(&node1);

    std::cout << "Number of nodes: " << count_nodes(&node1) << std::endl;

    return 0;
}