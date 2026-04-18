#include<iostream>
using namespace std;

class Stack{
    private:
        int top = -1;
        int arr[5];

        public:
        Stack(){
            for(int i=0; i<5 ; i++){
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            if(top == 5-1){
                return true;
            }
            else{
                return false;
            }
        }

        void push(int number){
            if(isFull()){
                std :: cout<<"Stack Overflowed"<<endl;
                return ;
            }
            else{
                top ++;
                arr[top] = number;
            }
        }

        int pop(){
            if(isEmpty()){
                std :: cout<<"Stack Underflowed..."<<endl;
                return 0;
            }
            else{
                int popedvalue = arr[top];
                arr[top] = 0;
                top --;
                return popedvalue;
            }
        }

        int change(int position , int value){
            
            if(position > top || arr[position] == value){
                return 0;
            }
            else{
                arr[position] = value;
                return arr[position];
            }
        }

        int count(){
            int count = 0;
            for(int i=0 ; i<=top ; i++){
                count ++;
            }
            return count;
        }

        void display(){
            for(int i =4; i>=0 ; i--){
                std :: cout<<arr[i]<<endl;
            }
        }


};

int main(){
    Stack s1;
    int option;
    int popednunmber;

    do{
        std :: cout<<"\n\nChose an option from the menu below:\n";
        std :: cout<<"1. isEmpty"<<endl;
        std :: cout<<"2. isFull"<<endl;
        std :: cout<<"3. Push"<<endl;
        std :: cout<<"4. Pop"<<endl;
        std :: cout<<"5. Change"<<endl;
        std :: cout<<"6. Count"<<endl;
        std :: cout<<"7. Display"<<endl;

        cout<<"Enter your option(0 to exit): "; 
        cin>>option;

        switch(option){
            
            case 1:
                {if(s1.isEmpty()){
                    std :: cout<<"Stack is Empty";
                }
                else{
                    std :: cout<<"Stack is not Empty";
                }
                break;}
                
            case 2:
                {if(s1.isFull()){
                    std :: cout<<"Stack is Full";
                }
                else{
                    std :: cout<<"Stack is not Full";
                }
                break;}
            
            case 3:
                {int n;
                std :: cout<<"Enter an integer to push: ";
                cin>>n;
                s1.push(n);
                break;}
            
            case 4:
                {popednunmber = s1.pop();
                std :: cout<<"Integer poped from stack is: "<<popednunmber<<endl;
                break;}
            
            case 5:
                {int value , position ; 
                std :: cout<<"Enter The Index of item: ";
                cin>>position;
                std :: cout<<"Enter The Value of item: ";
                cin>>value;

                int response = s1.change(position , value);
                if(response == 0){
                    std :: cout<<"Couldn't change value ...\n";
                }
                else{
                    std :: cout<<"Value changed successfully...\n";
                }
                break;}
            
            case 6:
                {std :: cout<<"The total integers in Stack are: "<<s1.count()<<endl;
                break;}            
            case 7:
                {std :: cout<<"All integers in Stack are given below: "<<endl;
                s1.display();
                break;}

            default:
                std :: cout<<"Please enter a valid choice"<<endl;
                break;
        }


    }while (option != 0);
 


    return 0;

}