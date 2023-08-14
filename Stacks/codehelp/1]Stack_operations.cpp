#include <iostream>
using namespace std ;

class Stack{


    public:
    int* arr;
    int top;
    int size;
    
    public:
   
    Stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
        
    }

    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;


        }else{
            cout<<"stack is full"<<endl;
        }
    }


    void pop(){
        if(top<0){
            cout<<"stack underflow"<<endl;
        }else {
            top--;
        }
    }

    int getTop(){
        if(top==-1){
            cout<<"there is no element in stack"<<endl;
        }else{
            int temp=arr[top];
            // cout<<"Top element is: "<<temp<<endl;
            return temp;
        }
    }

    void getsize(){
        // Prints number of valid elemeent present in stack. can't return size directly. because we are implementing stack with array so it will even return size of array after poping some stack elements by returning int size. thats why we return value of top+1
        cout<< "Size is: " << top+1 <<endl;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
};


int main(){
    Stack st(5);
    st.push(10);
    st.push(5);
    st.push(7);
    st.push(66);
    st.push(99);

    while(!st.isEmpty()) {
          cout << st.getTop() << " ";
          st.pop();
  }cout << endl;

  st.pop();

}