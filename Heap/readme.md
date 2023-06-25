# Max Heap

Max Heap is a C++ class that represents a max heap data structure. It provides operations to insert elements, extract the maximum element, check if the heap is empty, get the size of the heap, and sort the elements in descending order.

## Algorithms Used

The Max Heap class utilizes the following algorithms:

- **Heapify**: When a MaxHeap object is created with an initial set of elements, the `heapify` function is called to convert the elements into a max heap. It starts from the parent of the last element and sifts down each element to its proper position, ensuring that the max heap property is satisfied.

- **Insert**: The `insert` function allows you to add a new element to the heap. The element is appended to the end of the underlying vector, and then it is sifted up by comparing it with its parent until it reaches its correct position, maintaining the max heap property.

- **Extract**: The `extract` function removes and returns the maximum element (root) of the heap. The last element in the vector is moved to the root position, and then it is sifted down by comparing it with its children until it reaches its correct position, maintaining the max heap property.

- **Sort**: The `sort` function returns a new vector containing the elements of the heap in descending order. It achieves this by repeatedly extracting the maximum element from the heap and placing it at the end of the new vector.


## How to Use

1. Include the `max_heap.h` header file in your C++ project:

   ```cpp
   #include "max_heap.h"
   ```

2. Create a `MaxHeap` object by passing an initial set of elements as a `std::vector<int>` to the constructor:

   ```cpp
   std::vector<int> initialElements = {4, 8, 2, 5, 1};
   MaxHeap heap(initialElements);
   ```

3. Perform operations on the heap:

   - Insert an element into the heap:

     ```cpp
     heap.insert(10);
     ```

   - Get the maximum element (root) of the heap:

     ```cpp
     int maxElement = heap.peak();
     ```

   - Extract the maximum element from the heap:

     ```cpp
     int maxElement = heap.extract();
     ```

   - Check if the heap is empty:

     ```cpp
     bool isEmpty = heap.isEmpty();
     ```

   - Get the size of the heap:

     ```cpp
     int size = heap.getSize();
     ```

   - Sort the elements in descending order:

     ```cpp
     std::vector<int> sortedElements = heap.sort();
     ```

4. Print the elements of the heap:

   ```cpp
   heap.printHeap();
   ```
