#include<iostream>
#include<cstdlib>
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
            next  = NULL;
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
                ptr = ptr->next;
            }

            return temp;
        }

        void appendNode(Node *n){
            if(nodeExists(n->key) != NULL){
                cout<<"Node Already Exists..."<<endl;
            }
            else{
                Node* ptr = head;

                if (head == NULL){
                    head = n;
                }
                else{
                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = n; 
                }
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

        void updateNodeByKey(int k , int d){
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
                while(ptr != NULL){
                    cout<< ptr->key << "\t" << ptr->data << "\t" << ptr->next <<endl;
                    ptr = ptr->next;
                }
            }
        }
};

int main(){
    singlyLinkedList s;
    int option;
    int key1 , k1 , data1 ;

    do{
        cout<<"********Menu********\n";
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
                s.appendNode(n1);
                break;
                
            case 2:
                cout<<"Node Prepend Operation: \n";
                cout<<"Enter key of Node: "; cin>>key1;
                cout<<"Enter Data of Node: "; cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s.prependNode(n1);
                break;
            
            case 3:
                cout<<"Node Insert Operation: \n";
                
                cout<<"Enter Key of Node After which you want to insert a Node: "; cin>>k1;

                cout<<"Enter key of Node: "; cin>>key1;
                cout<<"Enter Data of Node: "; cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s.insertNode(k1 , n1);
                break;
            
            case 4:
                cout<<"Node Deletion Operation: \n";
                cout<<"Enter Key of Node that you want to delete: "; cin>>k1;
                s.deleteNodeByKey(k1);
                break;
            
            case 5:
                cout<<"Node Updation Operation: \n";
                cout<<"Enter key of Node that you want to update: "; cin>>key1;
                cout<<"Enter new data of Node: "; cin>>data1;
                s.updateNodeByKey(key1 , data1);
                break;
            
            case 6:
                s.display();
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