//g++ -O3 kth_smallest_element.cpp -o kth_smallest_element.exe
//Hoare's QuickSelect Algorithm

#include "kth_smallest_element.hpp"

int main()
{

    std::vector<int> xs;
    
    xs.push_back(5);
    xs.push_back(3);
    xs.push_back(1);
    xs.push_back(6);
    xs.push_back(4);
    xs.push_back(2);
    
    /*
    xs.push_back(2);
    xs.push_back(3);
    xs.push_back(1);
    xs.push_back(2);
    xs.push_back(4);
    xs.push_back(2);
    */

    auto result = get_kth_smallest(xs, 4);

    std::cout << result << std::endl;

    return 0;
}



