#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a number at a specific position in the linked list
    void addNumberAtIndex(int number, int index) {
        Node* newNode = new Node(number);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                std::cout << "Invalid index." << std::endl;
            }
        }
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.addNumberAtIndex(1, 0);  // Add 1 at index 0 (first position)
    list.addNumberAtIndex(3, 1);  // Add 3 at index 1
    list.addNumberAtIndex(2, 1);  // Add 2 at index 1 (middle position)

    std::cout << "Linked List: ";
    list.printList();  // Output: 1 2 3

    return 0;
}
