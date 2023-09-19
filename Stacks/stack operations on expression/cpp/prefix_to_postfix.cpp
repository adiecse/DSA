// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include<stack>
using namespace std;

void convert(string prefix, stack<string> &st){
    for(int i=prefix.length()-1;i>=0;  i--){
        char ch=prefix[i];
        
        if((!st.empty())&&(ch=='+'||ch=='-'||ch=='/'||ch=='*')){
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string val;
            val=op1+op2+ch;
            st.push(val);
           }else{
            string op(1,ch);
            st.push(op);
        }
    }
}

int main() {
    // Write C++ code here
   string prefix=("-+a*bc+de");
   stack<string> st;
   
   convert(prefix,st);
   cout<<"expression is : "<<st.top()<<endl;

    return 0;
}