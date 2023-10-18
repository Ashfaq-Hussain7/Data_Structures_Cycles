#include <iostream>
class Stack 
{
    private:
        static const int MAX_SIZE = 100; 
        int arr[MAX_SIZE];
        int top; 

    public:
        Stack() 
        {
            top = -1; 
        }

        void push(int value) 
        {
            if (top >= MAX_SIZE - 1) 
            {
                std::cout << "Stack Is Full!!" << std::endl;
                return;
            }
            arr[++top] = value;
        }

        void pop() 
        {
            if (isEmpty()) 
            {
                std::cout << "Stack Is Empty!!" << std::endl;
                return;
            }
            --top;
        }

        bool isEmpty() 
        {
            return top == -1;
        }

        int size() 
        {
            return top + 1;
        }
};

int main() 
{
    Stack myStack;
    std::cout << "\nPushing elements into the stack:" << std::endl;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    std::cout << "\nStack size: " << myStack.size() << std::endl;
    std::cout << "\nIs the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "\nPopping elements from the stack:" << std::endl;
    myStack.pop();
    myStack.pop();
    std::cout << "\nStack size: " << myStack.size() << std::endl;
    std::cout << "\nIs the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout<<"\n\n\n";
    return 0;
}
