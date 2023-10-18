#include <iostream>
struct Node 
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack 
{
    private:
        Node* top;
        int size;  

    public:
        Stack() : top(nullptr), size(0) {}

        void push(int value) 
        {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            size++;
        }

        void pop() 
        {
            if (isEmpty()) 
            {
                std::cout << "Stack is empty! Cannot pop." << std::endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }

        bool isEmpty() 
        {
            return top == nullptr;
        }

        int getSize() 
        {
            return size;
        }
};

int main() 
{
    Stack myStack;

    std::cout << "\nPushing elements into the stack:" << std::endl;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "\nStack size: " << myStack.getSize() << std::endl;
    std::cout << "\nIs the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "\nPopping elements from the stack:" << std::endl;
    myStack.pop();
    myStack.pop();

    std::cout << "\nStack size: " << myStack.getSize() << std::endl;
    std::cout << "\nIs the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout<<"\n\n\n";
    return 0;
}
