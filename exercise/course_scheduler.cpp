//g++ -O3 course_scheduler.cpp -o course_scheduler.exe

#include "course_scheduler.hpp"
#include <iostream>

int main()
{
    std::vector<std::vector<int>> p = {{1, 0}, {2, 1}, {2, 5}, {0, 3}, {4, 3}, {3, 5}, {4, 5}};
    int n = 6;

    if (can_finish(n, p)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}