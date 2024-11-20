#include <iostream>
#include <string>

class HashTable {
private:
    int size;
    std::string* keys;
    int* values;
    bool* isOccupied;

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
        keys = new std::string[size];
        values = new int[size];
        isOccupied = new bool[size];
        for (int i = 0; i < size; i++) {
            isOccupied[i] = false;
        }
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        while (isOccupied[index] && keys[index] != key) {
            index = (index + 1) % size;
        }
        keys[index] = key;
        values[index] = value;
        isOccupied[index] = true;
    }

    int search(const std::string& key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            if (keys[index] == key) {
                return values[index];
            }
            index = (index + 1) % size;
        }
        return -1;
    }

    bool deleteKey(const std::string& key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            if (keys[index] == key) {
                isOccupied[index] = false;
                int nextIndex = (index + 1) % size;
                while (isOccupied[nextIndex]) {
                    std::string rehashKey = keys[nextIndex];
                    int rehashValue = values[nextIndex];
                    isOccupied[nextIndex] = false;
                    insert(rehashKey, rehashValue);
                    nextIndex = (nextIndex + 1) % size;
                }
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (isOccupied[i]) {
                std::cout << "Bucket " << i << ": (" << keys[i] << ", " << values[i] << ")" << std::endl;
            } else {
                std::cout << "Bucket " << i << ": (empty)" << std::endl;
            }
        }
    }

    ~HashTable() {
        delete[] keys;
        delete[] values;
        delete[] isOccupied;
    }
};

int main() {
    HashTable hashTable(5);
    hashTable.insert("Tao", 10);
    hashTable.insert("Chuoi", 20);
    hashTable.insert("Cam", 30);
    hashTable.insert("Xoai", 40);
    hashTable.insert("Nho", 50);

    hashTable.display();

    std::cout << "\n Tim kiem 'Chuoi': " << hashTable.search("Chuoi") << std::endl;
    std::cout << " Tim kiem 'Nho': " << hashTable.search("Nho") << std::endl;

    hashTable.deleteKey("Cam");
    std::cout << "\n Sau khi xoa 'Cam':" << std::endl;
    hashTable.display();

    return 0;
}

