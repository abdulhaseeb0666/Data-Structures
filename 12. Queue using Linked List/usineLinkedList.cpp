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

class Queue{
public:
    Node* front;
    Node* rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }

    bool isEmpty(){
        return (front == NULL);
    }

    void enqueue(Node* n){

        // if key already exists (simple check)
        Node* temp = front;
        while(temp != NULL){
            if(temp->key == n->key){
                cout << "\nNode already exists...\n";
                return;
            }
            temp = temp->next;
        }

        if(front == NULL){
            front = rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }

        cout << "\nNode Enqueued Successfully...\n";
    }

    void dequeue(){

        if(front == NULL){
            cout << "\nQueue Underflow...\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        // if last element removed
        if(front == NULL){
            rear = NULL;
        }

        delete temp;

        cout << "\nNode Dequeued Successfully...\n";
    }

    void peek(){
        if(front == NULL){
            cout << "\nQueue is Empty...\n";
        }
        else{
            cout << "Front Node -> Key: " 
                 << front->key 
                 << " Data: " 
                 << front->data << endl;
        }
    }

    void count(){
        int c = 0;
        Node* temp = front;

        while(temp != NULL){
            c++;
            temp = temp->next;
        }

        cout << "\nTotal Nodes in Queue: " << c << endl;
    }

    void display(){
        if(front == NULL){
            cout << "\nQueue is Empty...\n";
            return;
        }

        Node* temp = front;

        cout << "\nKey\tData\tNext\n";
        while(temp != NULL){
            cout << temp->key << "\t" << temp->data << "\t" << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main(){

    Queue q1;
    int option;
    int key1, data1;

    do{
        cout << "\n\n******** Queue Menu ********\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Count\n";
        cout << "5. Display\n";
        cout << "6. IsEmpty\n";

        cout << "Enter Choice (0 to exit): ";
        cin >> option;

        switch(option){

        case 1:
            {
                Node* n = new Node();

                cout << "Enter Key: ";
                cin >> key1;

                cout << "Enter Data: ";
                cin >> data1;

                n->key = key1;
                n->data = data1;

                q1.enqueue(n);
                break;
            }

        case 2:
            q1.dequeue();
            break;

        case 3:
            q1.peek();
            break;

        case 4:
            q1.count();
            break;

        case 5:
            q1.display();
            break;

        case 6:
            if(q1.isEmpty())
                cout << "\nQueue is Empty...\n";
            else
                cout << "\nQueue is NOT Empty...\n";
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice...\n";
        }

    } while(option != 0);

    return 0;
}