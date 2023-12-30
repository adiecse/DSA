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



void compair(stack<int> &st,int key){
  int top=st.top();
  if(top>=key){
    st.push(key);
    return;
  }

  st.pop();
  compair(st,key);
  st.push(top);

}

int main() {
  stack<int> st;
  st.push(6);
  st.push(5);
  st.push(4);
  st.push(3);
  st.push(1);
  // reverse(st);
  int key=2;
  compair(st,key);
  print(st);
}
