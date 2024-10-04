//g++ -O3 kth_largest_element.cpp -o kth_largest_element.exe

#include "kth_largest_element.hpp" 

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
    

    auto result = get_kth_largest(xs, 2);

    std::cout << result << std::endl;

    return 0;
}