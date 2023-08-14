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

void insert_at_bottom(stack<int> &st ,int data){
  
  if(st.empty()){
    st.push(data);
    return;
  }
  int top_ele=st.top();
  st.pop();
  insert_at_bottom(st,5);
  st.push(top_ele);
  
  
}

int main() {
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  insert_at_bottom(st,5);
  print(st);
}