#include <iostream>
#include <list>
using namespace std;

#define SIZE 10

class HashTable {
    list<int> table[SIZE];

    int hash(int key) {
        return key % SIZE;
    }

public:
    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);
        cout << key << " inserted" << endl;
    }

    void search(int key) {
        int index = hash(key);
        for (int val : table[index]) {
            if (val == key) {
                cout << key << " found in hash table" << endl;
                return;
            }
        }
        cout << key << " not found" << endl;
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove(key);
        cout << key << " deleted (if it existed)" << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket " << i << ": ";
            for (int val : table[i]) {
                cout << val << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
