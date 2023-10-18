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

    void insert(int key) 
    {
        Node* newNode = new Node(key);
        if (!head) 
        {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) 
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to perform alternate splicing
    std::pair<LinkedList, LinkedList> alternateSplice() 
    {
        LinkedList list1;
        LinkedList list2;
        Node* current = head;
        while (current) 
        {
            list1.insert(current->data);
            if (current->next) 
            {
                current = current->next;
                list2.insert(current->data);
            }
            if (current) 
            {
                current = current->next;
            }
        }
        return std::make_pair(list1, list2);
    }
};

int main() 
{
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    std::cout << "\nOriginal list: ";
    list.display();
    std::pair<LinkedList, LinkedList> sublists = list.alternateSplice();
    std::cout << "\nList 1 after alternate splicing: ";
    sublists.first.display();
    std::cout << "\nList 2 after alternate splicing: ";
    sublists.second.display();
    std::cout<<"\n";
    return 0;
}
