#ifndef KTH_SMALLEST_ELEMENT
#define KTH_SMALLEST_ELEMENT

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>


//My Solution
int kth(std::vector<int>& xs, std::size_t first, std::size_t last, const int& k)
{
    auto bound = std::partition(xs.begin() + first + 1, xs.begin() + last,
                                [pivot = *(xs.begin() + first)](int x) { return x <= pivot; });
    
    std::swap(*(bound - 1), *(xs.begin() + first));
    int pos = std::distance(xs.begin(), bound - 1);
    
    if(pos == k) 
        return *(bound - 1);
    else if(pos < k)
        return kth(xs, pos + 1, last, k); 
    else 
        return kth(xs, first, pos, k);    
}


//----------------------------------------------------------------------------------------------


void swap_(std::vector<int>& array, const int& i, const int& j)
{
    const auto temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(std::vector<int>& array, const int& left, const int& right)
{
    const auto pivotElement = array[right];
    int partitionIdx = left;
    for(int j = left; j < right; ++j)
    {
        if(array[j] <= pivotElement)
        {
           swap_(array, partitionIdx, j);
           ++partitionIdx ;
        }
    }

    swap_(array, partitionIdx, right);

    return partitionIdx;
}

int quick_select_course(std::vector<int>& array, const int& left, const int& right, const int& kth)
{
    if(left < right)
    {
        const auto partitionIndex = partition(array, left, right);

        for(int i =0; i < array.size(); ++i)
        {
            std::cout << array[i] << std::endl;
        }
    


        if(kth == partitionIndex)
            return array[kth];
        else if(kth < partitionIndex)
            return quick_select_course(array, left, partitionIndex -1, kth);
        else
            return quick_select_course(array, partitionIndex + 1, right, kth);
    }
}

int get_kth_smallest(std::vector<int> array, int k)
{
    //My Solution
    return kth(array, 0, array.size(), k);
    //Course Solution
    //return quick_select_course(array, 0, array.size(), k);
}

#endif
