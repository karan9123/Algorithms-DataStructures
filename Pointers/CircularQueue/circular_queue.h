#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include <iostream>

/**
 * @brief CircularQueue Class
 */
class CircularQueue
{
private:
    int *queue;
    int front;
    int rear;
    int capacity;

public:
    /**
     * @brief Constructor to initialize CircularQueue
     * @param capacity The maximum number of elements the queue can hold
     */
    CircularQueue(int capacity) : capacity(capacity), front(-1), rear(-1), queue(new int[capacity]) {}

    /**
     * @brief Destructor to clean up the dynamically allocated memory
     */
    ~CircularQueue()
    {
        delete[] queue;
    }

    /**
     * @brief Checks if the circular queue is full
     * @return true if the queue is full, false otherwise
     */
    bool isFull()
    {
        return getSize() == capacity;
    }

    /**
     * @brief Checks if the circular queue is empty
     * @return true if the queue is empty, false otherwise
     */
    bool isEmpty()
    {
        return (front == rear && front == -1);
    }

    /**
     * @brief Adds an element to the rear of the circular queue
     * @param data The element to be enqueued
     */
    void enqueue(int data)
    {
        if (isFull())
        {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = data;
    }

    /**
     * @brief Removes the element from the front of the circular queue
     */
    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return;
        }
        front = (front + 1) % capacity;
    }

    /**
     * @brief Retrieves the element at the front of the circular queue without removing it
     * @return The element at the front of the queue
     */
    int getFront()
    {
        return queue[front];
    }

    /**
     * @brief Retrieves the element at the rear of the circular queue without removing it
     * @return The element at the rear of the queue
     */
    int getRear()
    {
        return queue[rear];
    }

    /**
     * @brief Calculates the current number of elements in the circular queue
     * @return The size of the queue
     */
    int getSize()
    {
        if (isEmpty())
        {
            return 0;
        }
        int size;
        if (front <= rear)
        {
            size = (rear - front + 1);
        }
        else
        {
            size = capacity - (front - rear) + 1;
        }
        return size;
    }

    /**
     * @brief Prints the elements in the circular queue
     */
    void print()
    {
        int temp;
        int size = getSize();
        if (size == 0)
        {
            std::cout << "Empty Queue\n";
            return;
        }
        std::cout << "Queue: ";
        for (int i = 0; i < size; i++)
        {
            temp = (front + i) % capacity;
            std::cout << queue[temp];
            if (i != size - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << " :: size: " << size << std::endl;
    }
};
#endif