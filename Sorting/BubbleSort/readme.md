# Bubble Sort Algorithm
This program demonstrates the Bubble Sort algorithm in C++. The Bubble Sort algorithm is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The algorithm continues until the entire list is sorted.

## How to Use
1. Make sure you have a C++ compiler installed on your system.
2. Clone or download the source code files from this repository.
3. Compile the code using the C++ compiler. For example:
```bash
g++ -o BubbleSort main.cpp
```

4. Run the executable generated. For example:
```bash
./main
```

## Input
The program initializes a vector of integers (my_vec) with the following values:

```
{15, 5, 24, 8, 1, 3, 16, 10, 20}
```
## Output
The program sorts the vector using the Bubble Sort algorithm and prints the sorted vector to the console. For example:


```
1, 3, 5, 8, 10, 15, 16, 20, 24,
```
## Algorithm Analysis

The **Bubble Sort algorithm** has an average and worst-case time complexity of **O(n^2)**, where n is the number of elements in the input vector. This makes it inefficient for sorting large lists. However, it has the advantage of simplicity and ease of implementation. It performs multiple passes through the vector, comparing adjacent elements and swapping them if necessary. Each pass guarantees that the largest element "bubbles" to the end of the unsorted portion of the vector.

Although Bubble Sort is not recommended for large datasets, it can be suitable for small lists or partially sorted lists. It has a small memory footprint and is stable, meaning it preserves the relative order of equal elements.

The performance of the Bubble Sort algorithm can be improved by adding an early termination condition. If no swaps are performed during a pass, it means the vector is already sorted, and the algorithm can terminate early. However, the worst-case time complexity remains the same.






