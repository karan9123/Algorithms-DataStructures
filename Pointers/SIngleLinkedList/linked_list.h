#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

// Node struct represents a single node in the linked list
struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class represents a linked list
class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor that initializes the linked list with a single node
    LinkedList(int data) : head(new Node(data)) {}

    // Function to reverse the linked list
    void reverse() {
        Node* next, *previous = nullptr;
        while (head) {
            next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }
        head = previous;
    }

    // Function to insert a node at the beginning of the linked list
    void insertBegining(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at the end of the linked list
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        newNode->next = nullptr;
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to delete a node from the linked list
    void deleteNode(int data) {
        Node* temp = head;
        while (temp) {
            if (temp->data == data) {
                temp->data = temp->next->data;
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
#endif // LINKED_LIST_H