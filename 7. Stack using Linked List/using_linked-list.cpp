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
            next = NULL;
        }
};

class Stack{
    public:
        Node* head = NULL;

        Node* nodeExist(int k){
            Node* ptr = head;
            Node* temp = NULL;

            if(head == NULL){
                return temp;
            }
            else{
                do{
                    if(ptr->key == k){
                        temp = ptr;
                        break;
                    }
                    ptr = ptr->next;
                }while(ptr != NULL);
            }

            return temp;
        }

        bool isEmpty(){
            bool isempty = false;

            if(head == NULL){
                isempty = true;
            }

            return isempty;
        }

        void push(Node *n){
            if(nodeExist(n->key) != NULL){
                cout<<"\nNode already exists...\n";
            }
            else{
                if(head == NULL){
                    head = n;
                }
                else{
                    n->next = head;
                    head = n;
                }
                cout<<"\nNode Pushed Successfully...\n";
            }
        }

        void pop(){
            if(head == NULL){
                cout<<"\nNo node exists...\n";
            }
            else{
                Node* ptr = head;
                head = head->next;
                delete ptr;
            }
        }

        void peek(){
            if(head == NULL){
                cout<<"\nNo node exists...\n";
            }
            else{
                cout<<"key\t\tData\t\tNext\n";
                cout<< head->key << "\t\t" << head->data << "\t\t" << head->next <<endl;
            }
        }
        
        void count(){
            Node* ptr = head;
            int count = 0;
            if(ptr == NULL){
                cout<<"\nNo node exists...\n";
            }
            else{
                do{
                    count++;
                    ptr = ptr->next;
                }while(ptr != NULL);
                cout<<"Number of nodes in Stack is: "<<count<<endl;
            }
        }

        void display(){
            Node* ptr = head;
            if(ptr == NULL){
                cout<<"\nNo node exists...\n";
            }
            else{
                cout<<"key\t\tData\t\tNext\n";
                do{
                    cout<< ptr->key << "\t\t" << ptr->data << "\t\t" << ptr->next <<endl;
                    ptr = ptr->next;
                }while(ptr != NULL);
            }
        }
};

int main(){
    Stack s1;
    int option;
    int key1 , data1 , k;

    do
    {
        cout<<"\n\n********Menu********\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Count\n";
        cout<<"5. Display\n";
        cout<<"6. Empty\n";
        cout<<"7. Clear Screen\n";

        cout<<"Enter Choice(0 to exit): "; cin>>option;

        Node* n1 = new Node();

        switch(option){
            case 0:
                break;

            case 1:
                cout<<"Enter Key:";
                cin>>key1;
                cout<<"Enter Data: ";
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s1.push(n1);
                break;

            case 2:
                s1.pop();
                break;

            case 3:
                s1.peek();
                break;

            case 4:
                s1.count();
                break;

            case 5:
                s1.display();
                break;

            case 6:
                if(s1.isEmpty()){
                    cout<<"\nStack is Empty...\n";
                }
                else{
                    cout<<"\nStack is not Empty...\n";
                }
                break;

            case 7:
                system("cls");
                break;

            default:
                cout<<"Please enter a valid choice...\n";
                break;
        }

    } while (option != 0);

}