# Insertion Sort
Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time. It iterates through the input elements, comparing each element with the previous ones and inserting it into its correct position in the sorted subarray.

## Algorithm
The algorithm works as follows:

1. Iterate over the array starting from the second element (i = 1) to the last element.
2. Store the current element (my_vec[i]) in a temporary variable (temp).
3. Initialize a variable j with the index of the previous element (i - 1).
4. Compare temp with each element (my_vec[j]) from right to left in the sorted subarray until j reaches the beginning or my_vec[j] is smaller than or equal to temp.
- If j reaches the beginning of the subarray and my_vec[0] is greater than temp, shift my_vec[0] to my_vec[1] and insert temp at the beginning.
- If my_vec[j] is greater than temp, shift my_vec[j] to my_vec[j + 1] and decrement j by 1.
- If my_vec[j] is smaller than or equal to temp, insert temp at position j + 1 in the sorted subarray.
5. Repeat steps 2-4 until all elements are processed.

## Complexity Analysis

The time complexity of Insertion Sort is **O(n^2)** in the worst and average cases, and **O(n)** in the best case (when the array is already sorted). This makes it efficient for small input sizes or partially sorted arrays.

The space complexity of the algorithm is O(1) since it uses a constant amount of additional memory.

## Usage
To use the Insertion Sort algorithm in your C++ program:

1. Copy the insertionSort function into your code.
2. Pass a std::vector<int> as a parameter to the insertionSort function to sort it in-place.
3. Run your program to see the sorted vector.


**Example:**

```cpp

#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& my_vec) {
    // Insertion Sort implementation
}

int main() {
    std::vector<int> my_vec = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    insertionSort(my_vec);
    
    // Print the sorted vector
    for (int i = 0; i < my_vec.size(); i++) {
        std::cout << my_vec[i] << " ";
    }
    
    return 0;
}
```

**Output:**

```
1 3 5 8 10 15 16 20 24
```

This will sort the vector in ascending order using the Insertion Sort algorithm.





