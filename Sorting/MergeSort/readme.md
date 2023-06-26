# Merge Sort Algorithm

This code demonstrates the implementation of the Merge Sort algorithm in C++. Merge Sort is an efficient, comparison-based sorting algorithm that divides the array into smaller subarrays, sorts them recursively, and then merges them to obtain a final sorted array.

## Algorithm Steps

The Merge Sort algorithm can be summarized in the following steps:

1. Divide the unsorted array into two halves by finding the middle index.
2. Recursively sort the two halves by calling the mergeSort function on each half.
3. Merge the two sorted subarrays into a single sorted array using the merge function.
4. Repeat the above steps until the array is completely sorted.

## How to Use

Follow the steps below to use the Merge Sort code:

1. Ensure you have a C++ compiler installed on your system.
2. Copy the code from the provided source file (main.cpp) into a new C++ project or source file.
3. Customize the input array `arr` in the main function according to your requirements.
4. Compile and run the code.
5. The sorted array will be displayed in the console output.

## Example

For the input array:
```cpp
std::vector<int> arr = {15, 5, 24, 8, 1, 3, 16, 10, 20};
```

The output will be:

```
1, 3, 5, 8, 10, 15, 16, 20, 24,
```

## Complexity Analysis

The Merge Sort algorithm has a time complexity of O(n log n) in all cases, where n is the number of elements in the array. This makes it one of the most efficient sorting algorithms. However, it has a space complexity of O(n) due to the use of additional memory during the merging process. Also, this is a stable sorting algorith, mmeaning it preserves the relative order of equal elements.