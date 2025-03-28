//g++ -O3 right_side_view_of_tree.cpp -o right_side_view_of_tree.exe

#include "right_side_view_of_tree.hpp"

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
    Node node11;
    node11.value = 11;
    
    node1.left = &node2;
    node1.right = &node3;

    node3.right = &node6;

    node2.left = &node4;
    node2.right = &node5;

    node4.right = &node7;
    node7.left = &node8;

    //node7.right=&node11;
    //node5.right=&node9;
    
    std::vector<int> v;

    auto result = right_side_view_of_tree_bfs(&node1);
    int level = 0;
    //right_side_view_of_tree_dfs(&node1, level, v);
    
    for (int val : result)
    {
        std::cout << val << std::endl;
    }
    
    return 0;
}