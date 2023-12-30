#include <iostream>
using namespace std;
#include<stack>
void reverse(stack<int> &st);
void print(stack<int> &st){
  while (!st.empty()) {
      cout << st.top() <<" ";
      st.pop();
  }
  return;
}

void insert_at_bottom(stack<int> &st ,int data){
  
  if(st.empty()){
    st.push(data);
    return;
  }
  int top_ele=st.top();
  st.pop();
  insert_at_bottom(st,data);
  st.push(top_ele);
  
  
  
}

void reverse(stack<int> &st){
  if(st.empty()){
    return;
  }
  int top=st.top();
  st.pop();
  reverse(st);
  
  insert_at_bottom(st,top);
  
}

int main() {
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  // reverse(st);
  print(st);
}