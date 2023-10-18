#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the end of the linked list
    void insert(int key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Search for the occurrence of key and return its positions
    void search(int key) {
        int position = 1;
        Node* current = head;
        bool found = false;

        while (current) {
            if (current->data == key) {
                std::cout << "Key found at position: " << position << std::endl;
                found = true;
            }
            current = current->next;
            position++;
        }

        if (!found) {
            std::cout << "NOT FOUND" << std::endl;
        }
    }

    // Count the number of times key is duplicated in the list
    void countDuplicates(int key) {
        int count = 0;
        Node* current = head;

        while (current) {
            if (current->data == key) {
                count++;
            }
            current = current->next;
        }

        if (count == 0) {
            std::cout << "NO DUPLICATES" << std::endl;
        } else {
            std::cout << "Number of duplicates for key: " << count << std::endl;
        }
    }

    // Remove duplicates of key, keeping only the first occurrence
    void removeDuplicates(int key) {
        if (!head) {
            return;
        }

        Node* current = head;
        while (current && current->next) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    // Insert an element at a specific position
    void insertPosition(int key, int pos) {
        if (pos <= 0) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        if (pos == 1) {
            Node* newNode = new Node(key);
            newNode->next = head;
            head = newNode;
            return;
        }

        int currentPosition = 1;
        Node* current = head;

        while (current && currentPosition < pos - 1) {
            current = current->next;
            currentPosition++;
        }

        if (!current) {
            std::cout << "LIST TOO SMALL" << std::endl;
            return;
        }

        Node* newNode = new Node(key);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // Insert elements into the list
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(10);
    list.insert(20);

    std::cout << "\n\nOriginal list: ";
    list.display();
    std::cout<<"\n";
    // Search for key and display positions
    list.search(10);
    std::cout<<"\n";
    // Count duplicates of key
    list.countDuplicates(10);
    std::cout<<"\n";
    // Remove duplicates of key
    list.removeDuplicates(10);
    std::cout << "List after removing duplicates of key 10: ";
    list.display();
    std::cout<<"\n";
    // Insert element at a specific position
    list.insertPosition(25, 3);
    std::cout << "List after inserting 25 at position 3: ";
    list.display();
    std::cout<<"\n\n";
    return 0;
}
