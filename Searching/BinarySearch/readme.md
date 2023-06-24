# Binary Search


Binary Search is an efficient searching algorithm that works on **sorted** arrays or lists. It repeatedly divides the search space in half until the target element is found or determined to be absent. This algorithm has a time complexity of **O(log n)**, making it significantly faster than linear search for large datasets.

This repository provides an implementation of the Binary Search algorithm in C++. It includes both iterative and recursive versions of the search.

## Usage

- Clone the repository or download the relevant files.

- Include the `binary_search.h` header file in your C++ program.


```cpp
#include "binary_search.h"
```

- Create an instance of the BinarySearch class by providing a sorted vector or array of elements.
```cpp

std::vector<int> my_vec = {1, 3, 5, 7, 9};
BinarySearch<int> binary_search(my_vec);
```
- Call the returnPos or returnPosRecursive method on the BinarySearch object to perform the search.
```cpp

int result = binary_search.returnPos(5);
int result = binary_search.returnPosRecursive(5);
```
Check the result to determine if the target element was found.
```cpp

if (result == -1) {
    std::cout << "Element not found." << std::endl;
} else {
    std::cout << "Element found at index " << result << "." << std::endl;
}
```
## Examples

The repository includes a main.cpp file with examples of how to use the Binary Search algorithm. You can run the file to see the algorithm in action.


## Acknowledgements
The Binary Search algorithm implementation in this repository is based on standard algorithmic principles.
