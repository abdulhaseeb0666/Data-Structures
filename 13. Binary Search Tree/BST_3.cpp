#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    Node* root;

    BST(){
        root = NULL;
    }

    // Insert function
    Node* insert(Node* root, int val){

        if(root == NULL){
            return new Node(val);
        }

        if(val < root->data){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }

        return root;
    }

    void insert(int val){
        root = insert(root, val);
        cout << "Inserted successfully...\n";
    }

    // Search function
    bool search(Node* root, int key){

        if(root == NULL){
            return false;
        }

        if(root->data == key){
            return true;
        }

        if(key < root->data){
            return search(root->left, key);
        }
        else{
            return search(root->right, key);
        }
    }

    // Inorder traversal (Left → Root → Right)
    void inorder(Node* root){

        if(root == NULL){
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void display(){
        cout << "\nBST (Inorder Traversal - Sorted Order): ";
        inorder(root);
        cout << endl;
    }

    void searchValue(int key){
        if(search(root, key)){
            cout << "\nValue Found in BST...\n";
        }
        else{
            cout << "\nValue NOT Found...\n";
        }
    }
};

int main(){

    BST tree;
    int option, value;

    do{
        cout << "\n\n******** BST MENU ********\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display (Inorder)\n";

        cout << "Enter choice (0 to exit): ";
        cin >> option;

        switch(option){

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            tree.searchValue(value);
            break;

        case 3:
            tree.display();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice...\n";
        }

    }while(option != 0);

    return 0;
}