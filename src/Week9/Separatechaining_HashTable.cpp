#include <iostream>
#include <list>
#include <string>

class HashTable {
private:
    int size;
    std::list<std::pair<std::string, int>>* table;

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % size;
        }
        return hash;
    }

public:
    HashTable(int size) {
        this->size = size;
        table = new std::list<std::pair<std::string, int>>[size];
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        for (auto& element : table[index]) {
            if (element.first == key) {
                element.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    int search(const std::string& key) {
        int index = hashFunction(key);
        for (auto& element : table[index]) {
            if (element.first == key) {
                return element.second;
            }
        }
        return -1;
    }

    bool deleteKey(const std::string& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (auto& element : table[i]) {
                std::cout << "(" << element.first << ", " << element.second << ") -> ";
            }
            std::cout << "nullptr" << std::endl;
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable hashTable(5);
    hashTable.insert("Tao", 10);
    hashTable.insert("Chuoi", 20);
    hashTable.insert("Cam", 30);
    hashTable.insert("Xoai", 40);
    hashTable.insert("Tao", 50);

    hashTable.display();

    std::cout << "\n Tim kiem 'Chuoi': " << hashTable.search("Chuoi") << std::endl;
    std::cout << " Tim kiem 'Cam': " << hashTable.search("Cam") << std::endl;

    hashTable.deleteKey("Chuoi");
    std::cout << "\n Sau khi xoa 'Chuoi':" << std::endl;
    hashTable.display();
    return 0;
}
