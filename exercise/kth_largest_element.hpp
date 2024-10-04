#ifndef KTH_LARGEST_ELEMENT
#define KTH_LARGEST_ELEMENT

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

//My Solution
static inline std::size_t median_of_3(std::vector<int>& xs, std::size_t pos0, std::size_t pos1, std::size_t pos2)
{
    auto first = xs.begin();
    using T = typename std::vector<int>::value_type;
    T& x0 = *(first + pos0); T& x1 = *(first + pos1); T& x2 = *(first + pos2);
    if (x1 < x0)
        return x2 < x0 ? (x1 < x2 ? pos2 : pos1) : pos0;
    return x2 < x1 ? (x0 < x2 ? pos2 : pos0) : pos1;
}

inline void quicksort(std::vector<int>& xs, std::size_t first, std::size_t last)
{
    assert(first <= last);

    const std::size_t N = last - first;

    if(N < 2) return;

    if(N ==2)
    {
        if(xs[first + 1] < xs[first])
            std::swap(xs[first + 1], xs[first]);
        return;
    }

    //swap first with median of 3
    std::size_t pos0 = first, pos1 = first + N / 2, pos2 = first + N - 1;

    std::swap(xs[median_of_3(xs, pos0, pos1, pos2)], xs[first]);
    
    auto pivot = xs.begin() + first;
    auto end = xs.begin() + last;
    auto bound = std::partition(pivot + 1, end, [&](typename std::vector<int>::const_reference x) {
        return x < *pivot;
    });
    if (pivot != bound)
    {
        std::swap(*pivot, *(bound - 1));
        std::size_t p = first + std::distance(pivot, bound);
        quicksort(xs, first, p - 1);
        quicksort(xs, p, last);
    }
}

//-----------------------------------------------------------------------------
//CourseSolution
void swap_(std::vector<int>& array, int i, int j)
{
    const auto temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(std::vector<int>& array, int left, int right)
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

void quicksort_course(std::vector<int>& array, const int& left, const int& right)
{
    if(left < right)
    {
        const auto partitionIndex = partition(array, left, right);

        quicksort_course(array, left, partitionIndex -1);
        quicksort_course(array, partitionIndex + 1, right);
    }
}

int get_kth_largest(std::vector<int> array, int k)
{
    auto indexToFind = array.size() - k;
    //Mine
    quicksort(array, 0, array.size());
    //Course
    //quicksort_course(array, 0, array.size() - 1);

    return array[indexToFind];
}

#endif