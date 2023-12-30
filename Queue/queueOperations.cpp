// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std; 
class queue{
    public:
    int* arr;
    int front;
    int rear;
    int size;
    queue(int size){
        this->size=size;
        arr=new int[size];
        this->front=0;
        this->rear=0;
    }
    
    void push(int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
        }else{
            arr[rear]=data;
            rear++;
        }
    }
    
    void pop(){
        if(rear==front){
            cout<<("can't pop the element queue is empty");
        }else {
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
        }
    }
    
    int getFront(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            return arr[front];
        }
    }
    
    bool isEmpty(){
        if(front==rear){
            return true;
        }
        return false;
    }
    
    int getSize(){
        return rear-front;
        
    }
};





int main() {
    queue q1(6);
    q1.push(10);
    if(q1.isEmpty()){
        cout<<"Yes Queue is Empty"<<endl;
    }else{
        cout<<"Queue is Not empty"<<endl;
    }
    cout<<q1.getFront()<<endl;
    q1.pop();
    if(q1.isEmpty()){
        cout<<"Yes Queue is Empty"<<endl;
    }else{
        cout<<"Queue is Not empty"<<endl;
    }
    
    return 0;
}
