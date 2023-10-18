#include <iostream>
class Queue 
{
    private:
        static const int MAX_SIZE = 100; 
        int arr[MAX_SIZE];
        int front; 
        int rear;  
        int size; 

    public: 
        Queue() 
        {
            front = rear = -1; 
            size = 0; 
        }

        void enqueue(int value) 
        {
            if (size >= MAX_SIZE) 
            {
                std::cout << "Queue Is Full!!" << std::endl;
                return;
            }

            if (isEmpty()) 
            {
                front = rear = 0;
            }   
            else 
            {
                rear = (rear + 1) % MAX_SIZE; 
            }

            arr[rear] = value;
            size++;
        }

        void dequeue() 
        {
            if (isEmpty()) 
            {
                std::cout << "Queue Is Empty!!" << std::endl;
                return;
            }

            if (front == rear) 
            {
                front = rear = -1; 
            } 
            else 
            {
                front = (front + 1) % MAX_SIZE; 
            }

            size--;
        }

        bool isEmpty() 
        {
            return size == 0;
        }

        int getSize() 
        {
            return size;
        }
};

int main() 
{
    Queue myQueue;

    std::cout << "\nEnqueuing elements into the queue:" << std::endl;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "\nQueue size: " << myQueue.getSize() << std::endl;
    std::cout << "\nIs the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "\nDequeuing elements from the queue:" << std::endl;
    myQueue.dequeue();
    myQueue.dequeue();

    std::cout << "\nQueue size: " << myQueue.getSize() << std::endl;
    std::cout << "\nIs the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout<<"\n\n\n";
    return 0;
}
