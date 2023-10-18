#include <iostream>

class CircularQueue 
{
    private:
        static const int MAX_SIZE = 100; 
        int arr[MAX_SIZE];
        int front; 
        int rear;  
        int size; 

    public:
        CircularQueue() 
        {
            front = rear = -1; 
            size = 0; 
        }

        void enqueue(int value) 
        {
            if ((rear + 1) % MAX_SIZE == front) 
            {
                std::cout << "Circular Queue Is Full!!" << std::endl;
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
                std::cout << "Circular Queue Is Empty!!" << std::endl;
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
    CircularQueue myCircularQueue;

    std::cout << "\nEnqueuing elements into the circular queue:" << std::endl;
    myCircularQueue.enqueue(1);
    myCircularQueue.enqueue(2);
    myCircularQueue.enqueue(3);

    std::cout << "\nCircular Queue size: " << myCircularQueue.getSize() << std::endl;
    std::cout << "\nIs the circular queue empty? " << (myCircularQueue.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "\nDequeuing elements from the circular queue:" << std::endl;
    myCircularQueue.dequeue();
    myCircularQueue.dequeue();

    std::cout << "\nCircular Queue size: " << myCircularQueue.getSize() << std::endl;
    std::cout << "\nIs the circular queue empty? " << (myCircularQueue.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout<<"\n\n\n";
    return 0;
}
