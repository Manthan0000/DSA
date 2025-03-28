#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int size;
    list<int>* table;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) {
        size = s;
        table = new list<int>[size];
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index])
            if (val == key) return true;
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " -> ";
            for (int val : table[i]) cout << val << " ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    ht.display();

    cout << (ht.search(15) ? "Found" : "Not Found") << endl;
    ht.remove(15);
    cout << (ht.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
