#include<iostream>
#include<cstdlib>
using namespace std;

class CircularQueue{
    private:
        int arr[5];
        int front = -1;
        int rear = -1;
        int size = 5;
        int itemCount;

    public:
        CircularQueue(){
            itemCount = 0;
            for(int i=0 ; i<5; i++){
                arr[i]=0;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            if((rear+1)%size == front){
                return true;
            }
            else{
                return false;
            }
        }


        void enque(int val){
            if(isFull()){
                cout<<"CircularQueue Overflowed...";
                return;
            }

            else if(isEmpty()){
                front = rear = 0;
                arr[rear] = val;
            }
            
            else{
                rear = (rear+1)%size;
                arr[rear] = val;
            }

            itemCount++;
            
        }

        int dequeue(){
            int popednumber = 0;

            if(isEmpty()){
                cout<<"CircularQueue Underflowed...";
                return 0;
            }

            else if(front == rear){
                popednumber = arr[front];
                arr[front] = 0;       
                front = -1;
                rear = -1;
            }
            
            else {
                popednumber = arr[front];
                arr[front] = 0;       
                front = (front+1)%size;
            }
            
            itemCount--;
            return popednumber;

        }

        int count(){
            return itemCount;
        }

        void display(){
            for(int i=0; i<5 ; i++){
                cout<<arr[i]<<"\t";
            }
        }


};

int main(){
    CircularQueue q1;
    int option , popednunmber;
    
    do{
        std :: cout<<"\n\nChose an option from the menu below:\n";
        std :: cout<<"1. isEmpty"<<endl;
        std :: cout<<"2. isFull"<<endl;
        std :: cout<<"3. Engueue"<<endl;
        std :: cout<<"4. Dequeue"<<endl;
        std :: cout<<"5. Count"<<endl;
        std :: cout<<"6. Display"<<endl;
        std :: cout<<"7. Clear Screen"<<endl;

        cout<<"Enter your option(0 to exit): "; 
        cin>>option;

        switch(option){
            
            case 1:
                {if(q1.isEmpty()){
                    std :: cout<<"CircularQueue is Empty";
                }
                else{
                    std :: cout<<"CircularQueue is not Empty";
                }
                break;}
                
            case 2:
                {if(q1.isFull()){
                    std :: cout<<"CircularQueue is Full";
                }
                else{
                    std :: cout<<"CircularQueue is not Full";
                }
                break;}
            
            case 3:
                {int n;
                std :: cout<<"Enter an integer to add to queue: ";
                cin>>n;
                q1.enque(n);
                break;}
            
            case 4:
                {popednunmber = q1.dequeue();
                std :: cout<<"Integer poped from stack is: "<<popednunmber<<endl;
                break;}
            
            
            case 5:
                {std :: cout<<"The total integers in CircularQueue are: "<<q1.count()<<endl;
                break;} 

            case 6:
                {std :: cout<<"All integers in CircularQueue are given below: "<<endl;
                q1.display();
                break;}

            case 7:
                {system("cls");
                break;}


            default:
                {std :: cout<<"Please enter a valid choice"<<endl;
                break;}
        }


    }while (option != 0);
    
    

}