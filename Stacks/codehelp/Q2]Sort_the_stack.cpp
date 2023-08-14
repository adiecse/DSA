#include <iostream>
using namespace std;
#include<stack>

void print(stack<int> &st){
  while (!st.empty()) {
      cout << st.top() <<" ";
      st.pop();
  }
  return;
}

void insert_in_sorted(stack<int> &st ,int data){
  cout<<"Entered sorted"<<endl;
  
  if(st.empty()){
    cout<<"hello"<<endl;
    st.push(data);
    return;
  }
  int top=st.top();
  cout<<top<<endl;
  if(top>=data){
    cout<<"Error if"<<endl;
    st.push(data);
    
    
  }else{
    cout<<"Error else"<<endl;
    st.pop();
    insert_in_sorted(st ,data);
    st.push(top);
  
  }
}

void compair(stack<int> &st){
  cout<<"Entered compair"<<endl;
  if(st.empty()){
    return;
  }

  int top=st.top();
  st.pop();
  compair(st);
  insert_in_sorted(st,top);
    
}

int main() {
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  // st.push(3);
  // st.push(1);
  // reverse(st);
  // int key=2;
  compair(st);
  print(st);
}
