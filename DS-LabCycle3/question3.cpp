#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node* prev; // Back pointer for doubly linked list

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList 
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int key) 
    {
        Node* newNode = new Node(key);
        if (!head) 
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void displayForward() 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void displayReverse() 
    {
        Node* current = tail;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() 
{
    int n;
    std::cin>>n;
    DoublyLinkedList doublyList;
    doublyList.insert(1);
    doublyList.insert(2);
    doublyList.insert(3);
    doublyList.insert(4);
    doublyList.insert(5);
    std::cout << "\nDoubly linked list contents from head to tail: ";
    doublyList.displayForward();
    std::cout << "\nDoubly linked list contents from tail to head: ";
    doublyList.displayReverse();
    std::cout<<"\n\n\n";
    return 0;
}
