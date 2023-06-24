# Linear Search
Linear search is a simple searching algorithm that sequentially checks each element of a collection until a match is found or the entire collection has been traversed. It is also known as a sequential search.

## Algorithm
The linear search algorithm follows these steps:

- Start at the beginning of the collection.
- Compare the target element with the current element.
- If a match is found, return the index or position of the current element.
- If the entire collection has been traversed without finding a match, return a sentinel value to indicate that the element is not present.
- Move to the next element in the collection and repeat steps 2-4 until a match is found or the end of the collection is reached.
## Example
Suppose we have an array of integers [4, 2, 9, 1, 7, 5] and we want to search for the element 7.

- Start at the beginning of the array.
- Compare 4 with 7. Not a match.
- Move to the next element 2.
- Compare 2 with 7. Not a match.
- Move to the next element 9.
- Compare 9 with 7. Not a match.
- Move to the next element 1.
- Compare 1 with 7. Not a match.
- Move to the next element 7.
- Compare 7 with 7. Match found! Return the index of 7 (which is 4).

The linear search algorithm traversed the entire array before finding the match in this example.

## Complexity
The time complexity of the linear search algorithm is **O(n)**, where **n** is the size of the collection being searched. This means that in the worst-case scenario, where the element is not present or located at the end of the collection, the algorithm may have to iterate through all elements.

The space complexity of the linear search algorithm is **O(1)** since it does not require any additional space proportional to the input size.

## Usage
To use the linear search algorithm in your code, follow these steps:

- Obtain the collection (e.g., an array, list, or sequence) in which you want to search for an element.
- Provide the target element that you want to find.
- Call the linear search function or method, passing the collection and target element as arguments.
- The algorithm will return the index or position of the target element if found, or a sentinel value if the element is not present.