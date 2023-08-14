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
  
  
  if(st.empty()){
    st.push(data);
    return;
  }
  int top=st.top();

  if(top>=data){

    st.push(data);
    
    
  }else{

    st.pop();
    insert_in_sorted(st ,data);
    st.push(top);
  
  }
}

void compair(stack<int> &st){

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
  st.push(9);
  st.push(7);
  st.push(13);
  // reverse(st);
  // int key=2;
  compair(st);
  print(st);
}
