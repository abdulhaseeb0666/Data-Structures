#include<iostream>
using namespace std;

class Node{
    public:
        long int key;
        long int data;
        Node* prev;
        Node* next;
        
        Node(){
            key = 0;
            data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(long int k , long int d){
            key = k;
            data = d;
            next  = NULL;
            prev = NULL;
        }
    };
    
class DoublyLinkedList{
        
    public:
        Node* head;
        
        DoublyLinkedList(){
            head = NULL;
        }
        
        DoublyLinkedList(Node *n){
            head = n;
        }

        Node* nodeExists(int k){
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr != NULL){
                if(ptr->key == k){
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        void appendNode(Node *n){
            if(nodeExists(n->key) != NULL){
                cout<<"Node Already Exists...\n";
            }
            else{
                if(head == NULL){
                    head = n;
                }
                else{
                    Node* ptr = head; 
                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->prev = ptr;
                }
                cout<<"\nNode Appended Successfully\n";
            }
        }

        void prependNode(Node *n){
            if(nodeExists(n->key) != NULL){
                cout<<"Node Already Exists...\n";
            }
            else{
                if(head == NULL){
                    head = n;
                }
                else{
                    head->prev = n;
                    n->next = head;
                    head = n;
                }
                cout<<"\nNode Prepended\n";
            }
        }

        void insertNode(int key , Node *n){
            if(nodeExists(n->key) != NULL){
                cout<<"Node Already Exists...\n";
            }
            else{
                if(head == NULL){
                    cout<<"\nNo Node Exists....\n";
                }
                else{
                    Node* prevNode = head;
                    Node* nextNode = head->next;
                    Node* actualNode = NULL;

                    while(prevNode != NULL){
                        if(prevNode->key == key){
                            actualNode = prevNode;
                            prevNode = NULL;
                        }
                        else{
                            prevNode = prevNode->next;
                            nextNode = nextNode->next;
                        }
                    }

                    if(actualNode == NULL){
                        cout<<"\nNode with the given key of "<< key <<" not found...\n";
                    }
                    else{
                        if(actualNode->next == NULL){
                            actualNode->next = n;
                            n->prev = actualNode;
                        }
                        else{
                            n->next = nextNode;
                            nextNode->prev = n;
                            actualNode->next = n;
                            n->prev = actualNode;
                        }
                        cout<<"\nNode Inserted Successfully\n";
                    } 
                }
            }
        }

        void deleteNode(int key){
            Node* ptr = nodeExists(key);
            if(ptr == NULL){
                cout<<"\nNo Node found with the given key...\n";
            }
            else{
                if(head == NULL){
                    cout<<"No Node Found....\n";
                }
                else{
                    if(head->key == key){
                        head = head->next;
                    }
                    else{
                        Node* prevNode = ptr->prev;
                        Node* nextNode = ptr->next;
                        
                        if(nextNode == NULL){
                            prevNode->next = nextNode;
                        }
                        else{
                            prevNode->next = nextNode;
                            nextNode->prev = prevNode;
                        }
                        cout<<"\nNode Deleted Successfully....\n";
                    }
                }
            }
        }

        void updateNode(int key , int data){
            Node* ptr = nodeExists(key);
            if(ptr == NULL || head == NULL){
                cout<<"\nNo Node Exists with this key\n";
            }
            else{
                ptr->data = data;
                cout<<"\nNode Updates Successfully...\n";
            }
        }

        void display(){
            if(head == NULL){
                cout<<"\nNo Node Exists...\n";
            }
            else{
                Node* ptr = head;
                cout<<"Key\tData\tPrev\tNext\n";
                while(ptr != NULL){
                    cout<< ptr->key << "\t" << ptr->data << "\t" << ptr->prev << "\t" << ptr->next <<endl;
                    ptr = ptr->next;
                }
            }
        }
};

int main(){
    DoublyLinkedList d;
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
                d.appendNode(n1);
                break;
                
            case 2:
                cout<<"Node Prepend Operation: \n";
                cout<<"Enter key of Node: "; cin>>key1;
                cout<<"Enter Data of Node: "; cin>>data1;
                n1->key = key1;
                n1->data = data1;
                d.prependNode(n1);
                break;
            
            case 3:
                cout<<"Node Insert Operation: \n";
                
                cout<<"Enter Key of Node After which you want to insert a Node: "; cin>>k1;

                cout<<"Enter key of Node: "; cin>>key1;
                cout<<"Enter Data of Node: "; cin>>data1;
                n1->key = key1;
                n1->data = data1;
                d.insertNode(k1 , n1);
                break;
            
            case 4:
                cout<<"Node Deletion Operation: \n";
                cout<<"Enter Key of Node that you want to delete: "; cin>>k1;
                d.deleteNode(k1);
                break;
            
            case 5:
                cout<<"Node Updation Operation: \n";
                cout<<"Enter key of Node that you want to update: "; cin>>key1;
                cout<<"Enter new data of Node: "; cin>>data1;
                d.updateNode(key1 , data1);
                break;
            
            case 6:
                d.display();
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