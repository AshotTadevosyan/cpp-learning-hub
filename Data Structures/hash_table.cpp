#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
    std::vector<std::list<std::pair<int, int> > > table;
    int m_size;

public:

    HashTable() = default;
    HashTable(int size) : m_size(size), table(size) {}
    ~HashTable() {}

    int hashFunction(int key);
    void insert(int key, int value);
    int search(int key);
    void remove(int key);

};

int HashTable::hashFunction(int key) 
{
    return key % m_size;
}

void HashTable::insert(int key, int value) 
{
    int index = hashFunction(key);
    table[index].push_back(std::make_pair(key, value));
}

int HashTable::search(int key) 
{
    int index = hashFunction(key);
    for (std::list<std::pair<int, int> >::iterator it = table[index].begin(); it != table[index].end(); ++it) 
    {
        if (it->first == key) 
        {
            return it->second;
        }
    }
    return -1;
}

void HashTable::remove(int key) 
{
    int index = hashFunction(key);
    for (std::list<std::pair<int, int> >::iterator it = table[index].begin(); it != table[index].end(); ++it) 
    {
        if (it->first == key) 
        {
            table[index].erase(it);
            return;
        }
    }
}


int main() {
    HashTable hashTable(10);

    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);

    std::cout << hashTable.search(2) << std::endl; // Output: 20

    hashTable.remove(2);

    std::cout << hashTable.search(2) << std::endl; // Output: -1

    return 0;
}
