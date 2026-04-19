#include<iostream>
using namespace std;

class Queue{
    private:
        int arr[5];
        int front = -1;
        int rear = -1;

    public:
        Queue(){
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
            if(rear == (sizeof(arr)/4)-1){
                return true;
            }
            else{
                return false;
            }
        }


        void enque(int val){
            if(isFull()){
                cout<<"Queue Overflowed...";
                return;
            }

            else if(isEmpty()){
                front = rear = 0;
                arr[rear] = val;
            }
            
            else{
                rear ++;
                arr[rear] = val;
            }
            
        }

        int dequeue(){
            int popednumber = 0;

            if(isEmpty()){
                cout<<"Queue Underflowed...";
                return 0;
            }

            if(front == rear){
                popednumber = arr[front];
                arr[front] = 0;       
                front = -1;
                rear = -1;
            }
            
            else {
                popednumber = arr[front];
                arr[front] = 0;       
                front ++;
            }
            
            return popednumber;

        }

        int count(){
            int number = 0;
            if(front == -1 && rear == -1){
                return number;
            }
            else{
                for(int i=front ; i<=rear ; ++i){
                    number ++;
                }
                return number;
            }
        }

        void display(){
            for(int i=0; i<5 ; i++){
                cout<<arr[i]<<"\t";
            }
        }


};

int main(){
    Queue q1;
    int option , popednunmber;
    
    do{
        std :: cout<<"\n\nChose an option from the menu below:\n";
        std :: cout<<"1. isEmpty"<<endl;
        std :: cout<<"2. isFull"<<endl;
        std :: cout<<"3. Engueue"<<endl;
        std :: cout<<"4. Dequeue"<<endl;
        std :: cout<<"5. Count"<<endl;
        std :: cout<<"6. Display"<<endl;

        cout<<"Enter your option(0 to exit): "; 
        cin>>option;

        switch(option){
            
            case 1:
                {if(q1.isEmpty()){
                    std :: cout<<"Queue is Empty";
                }
                else{
                    std :: cout<<"Queue is not Empty";
                }
                break;}
                
            case 2:
                {if(q1.isFull()){
                    std :: cout<<"Queue is Full";
                }
                else{
                    std :: cout<<"Queue is not Full";
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
                {std :: cout<<"The total integers in Queue are: "<<q1.count()<<endl;
                break;} 

            case 6:
                {std :: cout<<"All integers in Queue are given below: "<<endl;
                q1.display();
                break;}

            default:
                {std :: cout<<"Please enter a valid choice"<<endl;
                break;}
        }


    }while (option != 0);
    
    

}