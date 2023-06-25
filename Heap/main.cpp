#include <iostream>
#include "max_heap.h"

int main()
{
    std::vector<int> myHeap = {50, 30, 20, 15, 10, 8, 16};
    std::vector<int> myVec = {30, 15, 20, 8, 16, 50, 10};
    MaxHeap maxHeap(myVec);
    maxHeap.printHeap();
    maxHeap.insert(60);
    maxHeap.printHeap();
    std::vector<int> sortedArray;

    try
    {
        sortedArray = maxHeap.sort();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    for (int i = 0; i < sortedArray.size(); i++)
    {
        std::cout << sortedArray[i] << ", ";
    }
    std::cout << std::endl;
    maxHeap.printHeap();

    return 0;
}