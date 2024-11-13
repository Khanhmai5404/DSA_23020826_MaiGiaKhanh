#include <iostream>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

Node* Chen(Node * root, int key){
    if(root == NULL){
        return new Node(key);
    }
    if(key < root->key){
        root->left = Chen(root->left, key);
    } else {
        root->right = Chen(root->right, key);
    }
    return root;
}

bool TimKiem(Node * root, int key){
    if(root == NULL){
        return false;
    }
    if(root->key == key){
        return true;
    }
    if(key < root->key){
        return TimKiem(root->left, key);
    }
    return TimKiem(root->right, key);
}

void InKieuInOrder(Node *root){
    if(root == NULL){
        return;
    }
    InKieuInOrder(root->left);
    cout << root->key << " ,";
    InKieuInOrder(root->right);
}

Node* TimMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;//tim gia tri min
}

void InDay(Node* root, int k1, int k2){
    if(root == NULL){
        return;
    }
    if(root->key >= k1 && root->key <= k2){
        InDay(root->left, k1, k2);
        cout << root->key << " ";
        InDay(root->right, k1, k2);
    } else if(root->key > k2){
        InDay(root->left, k1, k2);
    } else {
        InDay(root->right, k1, k2);
    }
}

int main(){
    Node * root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 2, 7, 13};

    for(int x : arr){
        root = Chen(root, x);
    }
    InKieuInOrder(root);

    int key;
    cout <<"\n"<< "Day : " ;
    InDay(root, 1, 12);

    return 0;
}
