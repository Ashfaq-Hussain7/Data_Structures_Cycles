#include <iostream>
#include <vector>
struct Node 
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
struct Bucket 
{
    Node* head;
    Bucket() : head(nullptr) {}
    void insert(int key) 
    {
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }
    void remove(int key) 
    {
        Node* current = head;
        Node* prev = nullptr;
        while (current) 
        {
            if (current->data == key) 
            {
                if (prev) 
                {
                    prev->next = current->next;
                } 
                else 
                {
                    head = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    bool search(int key) 
    {
        Node* current = head;
        while (current) 
        {
            if (current->data == key) 
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class HashTable 
{
    private:
        static const int TABLE_SIZE = 10; 
        std::vector<Bucket> table; 
        int hash(int key) 
        {
            return key % TABLE_SIZE;
        }

    public:
        HashTable() : table(TABLE_SIZE) {} 
        void insert(int key) 
        {
            int index = hash(key);
            table[index].insert(key);
        }
        void remove(int key) 
        {
            int index = hash(key);
            table[index].remove(key);
        }
        bool search(int key) 
        {
            int index = hash(key);
            return table[index].search(key);
        }
};

int main() {
    HashTable myHashTable;
    myHashTable.insert(5);
    myHashTable.insert(15);
    myHashTable.insert(25);
    myHashTable.insert(35);
    std::cout << "\nSearching for keys:" << std::endl;
    std::cout << "\nKey 5: " << (myHashTable.search(5) ? "Found" : "Not Found") << std::endl;
    std::cout << "\nKey 10: " << (myHashTable.search(10) ? "Found" : "Not Found") << std::endl;
    myHashTable.remove(25);
    std::cout << "\nKey 25: " << (myHashTable.search(25) ? "Found" : "Not Found") << std::endl;
    std::cout<<"\n\n\n";
    return 0;
}
