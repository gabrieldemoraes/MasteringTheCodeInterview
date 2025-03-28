//g++ -O3 level_order_of_binary_search_tree.cpp -o level_order_of_binary_search_tree.exe

#include "level_order_of_binary_search_tree.hpp"

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
    
    node1.left = &node3;
    node1.right = &node2;

    node2.left = &node5;
    node2.right = &node4;

    node4.left = &node6;
    
    node6.left = &node7;

    level_order_of_binary_tree(&node1);

    return 0;
}