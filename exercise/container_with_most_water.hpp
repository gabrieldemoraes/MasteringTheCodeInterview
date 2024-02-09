#include <vector>
#include <algorithm>

int greatest_amount_brute_force(std::vector<int> &array)
{
    int max_area = 0; 
    int a, b, r;

    for(int i = 0; i < array.size(); ++i)
    {
        a = array[i];
        for(int j = 1; j < array.size(); ++j)
        {
            b = array[j];
            r = std::min(a, b)*(j-i); //formula of the area
            max_area = std::max(max_area, r);
        }
    }

    return max_area;    
    
}

int greatest_amount_two_pointers(std::vector<int> &array)
{
    int max_area = 0, i = 0, j = array.size() - 1; 
    int a, b, r;
    while(i < j)
    {
        a = array[i];
        b = array[j];
        r = std::min(a, b)*(j-i); //formula of the area
        max_area = std::max(max_area, r);

        if(a <= b) ++i;
        else --j;
    }
    return max_area;    
}