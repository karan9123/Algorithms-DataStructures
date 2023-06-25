#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <vector>
#include <iostream>

/**
 * @brief MaxHeap class represents a max heap data structure.
 */
class MaxHeap
{
private:
    std::vector<int> heap_; // Internal storage for the heap elements
    int size_;              // Current size of the heap

public:
    /**
     * @brief Constructs a MaxHeap object with an initial set of elements.
     * @param given_heap The initial set of elements for the heap.
     */
    MaxHeap(const std::vector<int> &given_heap) : heap_(given_heap), size_(given_heap.size())
    {
        heapify(); // Transform the elements into a max heap
    };

    /**
     * @brief Inserts a new value into the heap.
     * @param value The value to be inserted.
     */
    void insert(int value)
    {
        heap_.push_back(value); // Add the new value at the end of the heap
        size_++;                // Increment the size of the heap

        // Restore the max heap property by comparing the new value with its parent
        if (size_ > 0)
        {
            int child = size_ - 1;
            int parent = (child - 1) / 2;
            while (parent >= 0)
            {
                parent = (child - 1) / 2;
                if (heap_[child] > heap_[parent])
                {
                    std::swap(heap_[child], heap_[parent]);
                    child = parent;
                }
                else
                {
                    break;
                }
            }
        }
    }

    /**
     * @brief Prints the elements of the heap.
     */
    void printHeap()
    {
        int heapSize = heap_.size();
        for (int i = 0; i < heapSize; i++)
        {
            std::cout << heap_[i] << ", ";
        }
        std::cout << std::endl;
    }

    /**
     * @brief Returns the maximum element (root) of the heap.
     * @return The maximum element.
     * @throws std::runtime_error if the heap is empty.
     */
    int peak()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Heap is empty");
        }
        else
        {
            return heap_[0];
        }
    }

    /**
     * @brief Removes and returns the maximum element (root) of the heap.
     * @return The maximum element.
     * @throws std::runtime_error if the heap is empty.
     */
    int extract()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Heap is empty");
        }
        else
        {
            int ret_val = heap_[0];      // Store the maximum element
            heap_[0] = heap_[size_ - 1]; // Replace the root with the last element
            heap_.pop_back();            // Remove the last element
            size_--;                     // Decrement the size of the heap

            int elementPos = 1;
            while (elementPos <= size_)
            {
                int leftChild = 2 * elementPos;
                int rightChild = 2 * elementPos + 1;
                int largest = elementPos - 1;

                // Find the index of the larger child
                if (leftChild < size_ && heap_[leftChild] > heap_[largest])
                {
                    largest = leftChild;
                }
                if (rightChild < size_ && heap_[rightChild] > heap_[largest])
                {
                    largest = rightChild;
                }

                // If the parent is smaller than the larger child, swap them and continue
                if (heap_[elementPos - 1] < heap_[largest])
                {
                    std::swap(heap_[elementPos - 1], heap_[largest]);
                    elementPos = largest + 1;
                }
                else
                {
                    break;
                }
            }

            return ret_val;
        }
    }

    /**
     * @brief Checks if the heap is empty.
     * @return True if the heap is empty, false otherwise.
     */
    bool isEmpty()
    {
        return size_ == 0;
    }

    /**
     * @brief Returns the size of the heap.
     * @return The size of the heap.
     */
    int getSize()
    {
        return size_;
    }

    /**
     * @brief Sorts the elements of the heap in descending order and returns them in a new vector.
     * @return A vector containing the sorted elements.
     */
    std::vector<int> sort()
    {
        std::vector<int> retVector(size_, 0);
        std::vector<int> tempVector = heap_;
        for (int i = size_ - 1; i >= 0; i--)
        {
            int val = extract();
            retVector[i] = val;
        }
        heap_ = tempVector;
        return retVector;
    }

private:
    /**
     * @brief Converts the elements of the heap into a max heap.
     */
    void heapify()
    {
        for (int i = size_ / 2 - 1; i >= 0; i--)
        {
            siftDown(i);
        }
    }

    /**
     * @brief Restores the max heap property by sifting down an element at the given index.
     * @param index The index of the element to sift down.
     */
    void siftDown(int index)
    {
        int parent = index;
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;

        int largest = parent;

        if (leftChild < size_ && heap_[leftChild] > heap_[largest])
        {
            largest = leftChild;
        }

        if (rightChild < size_ && heap_[rightChild] > heap_[largest])
        {
            largest = rightChild;
        }

        if (largest != parent)
        {
            std::swap(heap_[parent], heap_[largest]);
            siftDown(largest);
        }
    }
};

#endif
