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

        Node(int k, int d){
            key = k;
            data = d;
            next = NULL;
        }
};

class CircularLinkedList{
    public:
        Node* head = NULL;

        Node* nodeExists(int k){
            Node* ptr = head;
            Node* temp = NULL;

            if(head == NULL){
                return temp;
            }

            else{
                do{
                    if(ptr->key == k){
                        temp = ptr;
                    }
                    ptr = ptr->next;
                } while(ptr != head);
                return temp;
            }
            
        }

        void appendNode(Node *n){
            if(head == NULL){
                head = n;
                n->next = head;
                cout<<"\nNode Appended Successfully...\n";
            }
            else{
                if(nodeExists(n->key) != NULL){
                    cout<<"\nNode Already Exists...\n";
                }
                else{
                    Node* ptr = head;

                    while(ptr->next != head){
                        ptr = ptr->next;
                    }

                    ptr->next = n;
                    n->next = head;
                    cout<<"\nNode Appended Successfully...\n";
                }
            }
        }

        void prependNode(Node *n){
            if(head == NULL){
                head = n;
                n->next = head;
                cout<<"\nNode Prepended Successfully...\n";
            }
            else{
                if(nodeExists(n->key) != NULL){
                    cout<<"\nNode Already Exists...\n";
                }
                else{
                    Node* ptr = head;
                    while(ptr->next != head){
                        ptr = ptr->next;
                    }
                    ptr->next = n;

                    n->next = head;
                    head = n;
                }
                cout<<"\nNode Prepended Successfully...\n";
            }
        }

        void insertNode(int k , Node *n){
            if(head == NULL){
               cout<<"\nNo Node Exists...\n";
            }
            else{
                if(nodeExists(n->key) != NULL){
                    cout<<"\nNode Already Exists...\n";
                }
                else{
                    Node* ptr = head;

                    do{
                        if(ptr->key == k) break;
                        ptr = ptr->next;
                    } while(ptr != head);
                    
                    if(ptr->key != k){
                        cout<<"Key not found\n";
                        return;
                    }
 
                    if(ptr->next == head){
                        ptr->next = n;
                        n->next = head;
                    }
                    else{
                        n->next = ptr->next;
                        ptr->next = n;
                    }
                    cout<<"\nNode Inserted Successfully...\n";
                }
            }
        }

        void deleteNode(int key){
            Node* ptr = nodeExists(key);
            if(ptr == NULL){
                cout<<"\nNo node found with the given key...\n";
            }
            else{
                Node* prevNode = NULL;
                Node* currentNode = head;
                
                do{
                    if(currentNode == ptr) break;
                    prevNode = currentNode;
                    currentNode = currentNode->next;
                } while(currentNode != head);

                if(ptr == head){
                    Node* last = head;
                    while(last->next != head){
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                    delete ptr;
                }

                else if(ptr->next == head){
                    prevNode->next = head;
                    delete ptr;
                }
                
                else{
                    prevNode->next = ptr->next;
                    delete ptr;
                }
                cout<<"\nNode deleted successfully...\n";
            
            }
        }

         void updateNodeByKey(long int k , long int d){
            Node* ptr = nodeExists(k);

            if(ptr == NULL){
                cout<<"Node Node with this key valye exists..."<<endl;
            }
            else{
                ptr->data = d;
                cout<<"Node Updated Successfully..."<<endl;
            }
        }

        void display(){
            if(head == NULL){
                cout<<"No Node Exists..."<<endl;
            }
            else{
                Node* ptr = head;
                cout<<"key\t\tData\t\tAddress\n";
                do{
                    cout << ptr->key << "\t\t" << ptr->data << "\t\t" << ptr->next << endl;
                    ptr = ptr->next;
                } while(ptr != head);
            }
        }
};

int main(){
    CircularLinkedList c;

    long int option;
    long int key1 , k1 , data1 ;

    do{
        cout<<"\n\n********Menu********\n";
        cout<<"1. Append Node"<<endl;
        cout<<"2. Prepend Node"<<endl;
        cout<<"3. Insert Node"<<endl;
        cout<<"4. Delete Node"<<endl;
        cout<<"5. Update Node"<<endl;
        cout<<"6. Print List"<<endl;
        cout<<"7. Clear Screen"<<endl;

        cout<<"Enter Choice(0 to exit): ";
        cin>>option;

        Node* n1 = new Node();

        switch(option){

            case 0:
                break;

            case 1:
                cout<<"Node Append Operation: \n";
                cout<<"Enter key of Node: "; cin>>key1;
                cout<<"Enter Data of Node: "; cin>>data1;
                n1->key = key1;
                n1->data = data1;
                c.appendNode(n1);
                break;
                
            case 2:
                cout<<"Node Prepend Operation: \n";
                cout<<"Enter key of Node: "; cin>>key1;
                cout<<"Enter Data of Node: "; cin>>data1;
                n1->key = key1;
                n1->data = data1;
                c.prependNode(n1);
                break;
            
            case 3:
                cout<<"Node Insert Operation: \n";
                
                cout<<"Enter Key of Node After which you want to insert a Node: "; cin>>k1;

                cout<<"Enter key of Node: "; cin>>key1;
                cout<<"Enter Data of Node: "; cin>>data1;
                n1->key = key1;
                n1->data = data1;
                c.insertNode(k1 , n1);
                break;
            
            case 4:
                cout<<"Node Deletion Operation: \n";
                cout<<"Enter Key of Node that you want to delete: "; cin>>k1;
                c.deleteNode(k1);
                break;
            
            case 5:
                cout<<"Node Updation Operation: \n";
                cout<<"Enter key of Node that you want to update: "; cin>>key1;
                cout<<"Enter new data of Node: "; cin>>data1;
                c.updateNodeByKey(key1 , data1);
                break;
            
            case 6:
                c.display();
                break;
            
            case 7:
                system("cls"); 
                break;
            
            default:
                cout<<"Please Enter a valid Choice"<<endl;
                break;
        }
    }while(option != 0);
}