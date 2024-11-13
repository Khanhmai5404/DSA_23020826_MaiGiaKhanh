#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    vector<int> keys;
    vector<Node*> children;

    Node(int key) {
        keys.push_back(key);
        children.resize(4, nullptr);  
    }
};

int findPosition(Node* node, int key) {
    int pos = 0;
    while (pos < node->keys.size() && node->keys[pos] < key) {
        pos++;
    }
    return pos;
}

void splitNode(Node* parent, int index, Node* node) {
    int middleKey = node->keys[1];
    Node* newNode = new Node(node->keys[2]);

    newNode->children[0] = node->children[2];
    newNode->children[1] = node->children[3];

    node->keys.resize(1);
    node->children[2] = nullptr;
    node->children[3] = nullptr;

    parent->keys.insert(parent->keys.begin() + index, middleKey);
    parent->children.insert(parent->children.begin() + index + 1, newNode);
}

void insertIntoNonFullNode(Node* node, int key) {
    int pos = findPosition(node, key);
    if (node->children[pos] == nullptr) {
        node->keys.insert(node->keys.begin() + pos, key);
        return;
    }

    Node* childNode = node->children[pos];
    if (childNode->keys.size() == 3) {
        splitNode(node, pos, childNode);
        if (key > node->keys[pos]) {
            pos++;
        }
    }

    insertIntoNonFullNode(node->children[pos], key);
}

void insert(Node*& root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return;
    }

    if (root->keys.size() == 3) {
        Node* newRoot = new Node(root->keys[1]);
        newRoot->children[0] = root;
        splitNode(newRoot, 0, root);
        root = newRoot;
    }

    insertIntoNonFullNode(root, key);
}

void inorder(Node* root) {
    if (root == nullptr) return;

    for (int i = 0; i < root->keys.size(); i++) {
        inorder(root->children[i]);
        cout << root->keys[i] << " ";
    }
    inorder(root->children[root->keys.size()]);
}

int main() {
    Node* root = nullptr;

    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 6);
    insert(root, 30);
    insert(root, 15);
    
    cout << "In-order traversal of 2-3 tree: ";
    inorder(root);
    cout << endl;

    return 0;
}

