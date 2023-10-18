#include <iostream>
#include <vector>
class HashTable 
{
    private:
        static const int TABLE_SIZE = 10; 
        std::vector<int> table; 
        int hash1(int key) 
        {
            return key % TABLE_SIZE;
        }
        int hash2(int key) 
        {
            return 7 - (key % 7);
        }

    public:
        HashTable() : table(TABLE_SIZE, -1) {} 
        void insert(int key) 
        {
            int index = hash1(key);
            if (table[index] == -1) 
            {
                table[index] = key;
            }    
            else 
            {
                int step = hash2(key);
                while (table[index] != -1) 
                {
                    index = (index + step) % TABLE_SIZE;
                }
                table[index] = key;
            }
        }
        void remove(int key) 
        {
            int index = hash1(key);
            if (table[index] == key) 
            {
                table[index] = -1;
                return;
            }
            int step = hash2(key);
            while (table[index] != key) 
            {
                if (table[index] == -1) 
                {
                    std::cout << "Key not found in the hash table." << std::endl;
                    return;
                }
                index = (index + step) % TABLE_SIZE;
            }
            table[index] = -1;
        }
        bool search(int key) 
        {
            int index = hash1(key);
            if (table[index] == key) 
            {
                return true;
            }
            int step = hash2(key);
            while (table[index] != key) 
            {
                if (table[index] == -1) 
                {
                    return false;
                }
                index = (index + step) % TABLE_SIZE;
            }
            return true;
        }
};

int main() 
{
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
