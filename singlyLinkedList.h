//
// Created by clane on 23.05.2024.
//

#ifndef HW01_02_SINGLYLINKEDLIST_H
#define HW01_02_SINGLYLINKEDLIST_H


#include <iostream>

// Node class
class Node {
public:
    int data;  // The data stored in the node
    Node* next;  // Pointer to the next node in the list

    // Constructor that initializes the node with the given data and sets the next pointer to nullptr
    Node(int data) : data(data), next(nullptr) {}
};

// SinglyLinkedList class
class SinglyLinkedList {
private:
    Node* head;  // Pointer to the first node in the list
    int size;  // The number of nodes in the list

public:
    // Constructor that initializes an empty list
    SinglyLinkedList() : head(nullptr), size(0) {}

    // Destructor that deletes all nodes in the list
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to insert a node at a specific position in the list
    void insertAt(int index, int data) {
        // If the index is out of bounds, do nothing
        if (index < 0 || index > size) {
            return;
        }

        // Create a new node with the given data
        Node* newNode = new Node(data);

        // If the index is 0, insert the new node at the beginning of the list
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            // Otherwise, find the node that will be before the new node
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            // Insert the new node after it
            newNode->next = temp->next;
            temp->next = newNode;
        }
        // Increase the size of the list
        size++;
    }

    // Method to remove a node at a specific position in the list
    void removeNodeAt(int index) {
        // If the index is out of bounds, do nothing
        if (index < 0 || index >= size) {
            return;
        }

        // If the index is 0, remove the first node
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            // Otherwise, find the node before the one to remove
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            // Remove the node after it
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        // Decrease the size of the list
        size--;
    }

    // Method to insert a node at the beginning of the list
    void insertAtFirst(int data) {
        // Create a new node with the given data
        Node* newNode = new Node(data);
        // The new node's next pointer points to the current first node
        newNode->next = head;
        // The new node becomes the first node
        head = newNode;
        // Increase the size of the list
        size++;
    }

    // Method to insert a node at the end of the list
    void insertAtLast(int data) {
        // Create a new node with the given data
        Node* newNode = new Node(data);
        // If the list is empty, the new node becomes the first node
        if (head == nullptr) {
            head = newNode;
        } else {
            // Otherwise, find the last node
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // The new node becomes the next node of the last node
            temp->next = newNode;
        }
        // Increase the size of the list
        size++;
    }

    // Method to remove the first node
    void removeFirstNode() {
        // If the list is not empty
        if (head != nullptr) {
            // Save the first node in a temporary pointer
            Node* temp = head;
            // The second node becomes the first node
            head = head->next;
            // Delete the old first node
            delete temp;
            // Decrease the size of the list
            size--;
        }
    }

    // Method to remove the last node
    void removeLastNode() {
        // If the list is not empty
        if (head != nullptr) {
            // If there is only one node, delete it and set the head pointer to nullptr
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                // Otherwise, find the second last node
                Node* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                // Delete the last node and set the next pointer of the second last node to nullptr
                delete temp->next;
                temp->next = nullptr;
            }
            // Decrease the size of the list
            size--;
        }
    }

// Method to print all nodes in the list and the size of the list
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\nSize of the list: " << size << std::endl;
    }
};

#endif //HW01_02_SINGLYLINKEDLIST_H
