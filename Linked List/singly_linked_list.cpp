#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;
        
        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int k , int d){
            key = k;
            data = d;
        }
};

class singlyLinkedList{
    public:
        Node* head;
        
        singlyLinkedList(){
            head = NULL;
        }
        
        singlyLinkedList(Node* n){
            head = n;     
        }

        Node* nodeExists(int k){
            Node* temp = NULL;

            Node* ptr = head;

            while(ptr != NULL){
                if(ptr -> key == k){
                    temp = ptr;
                }
            }

            return temp;
        }

        void appendNode(Node *n){
            if(nodeExists(n->key) != NULL){
                cout<<"Node Already Exists..."<<endl;
            }
            else{
                Node* ptr = head;
                
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }

                ptr->next = n; 
                cout<<"Node Appended"<<endl;
            }
        }
        
        void prependNode(Node *n){
            if(nodeExists(n->key) != NULL){
                cout<<"Node Already Exists..."<<endl;
            }
            else{
                n->next = head;
                head = n;
                cout<<"Node Prepended"<<endl;
            }
        }

        void insertNode(int k , Node *n){
            Node* ptr = nodeExists(k);
            if(ptr == NULL){
                cout<<"No Node Exits..."<<endl;
            }
            else{
                if(nodeExists(n->key) != NULL){
                    cout<<"Node to be inserted already exists..."<<endl;
                }
                else{
                    n->next = ptr->next;
                    ptr->next = n;
                    cout<<"Node Inserted"<<endl;
                }
            }
        }

        void deleteNodeByKey(int k){
            if(head == NULL){
                cout<<"Node does not exists..."<<endl;
            }
            else if(head != NULL){
                if(head->key == k){
                    head = head->next;
                    cout<<"Node Deleted of Key Value: "<<k<<endl;
                }
                else{
                    Node* temp = NULL;
                    Node* prevNode = head;
                    Node* currentNode = head->next;

                    while(currentNode != NULL){
                        if(currentNode->key == k){
                            temp = currentNode;
                            currentNode = NULL;
                        }
                        else{
                            prevNode = prevNode->next;
                            currentNode = currentNode->next;
                        }
                    }

                    if(temp == NULL){
                        cout<<"No Node Found with key value "<< k <<endl;
                    }
                    else{
                        prevNode->next = temp->next;
                        cout<<"Node of key "<< k <<" is Deleted successfully"<<endl;
                    }
                }
            }
        }

        void updateNodeByKey(){
            
        }

};

int main(){

}