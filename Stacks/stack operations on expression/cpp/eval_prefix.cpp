// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include<stack>
using namespace std;

void convert(string prefix, stack<int> &st){
    for(int i=prefix.length()-1;i>=0;  i--){
        char ch=prefix[i];
        
        if((!st.empty())&&(ch=='+'||ch=='-'||ch=='/'||ch=='*')){
            int first_operand=st.top();
            st.pop();
            int second_operand=st.top();
            st.pop();
            int val=0;
            switch(ch){
                case '+':
                    val=first_operand+second_operand;
                    //cout<<"val is addition: "<<val<<endl;
                    break;
            
                case '-':
                    val=first_operand-second_operand;
                    break;    
                    
                case '*':
                    val=first_operand*second_operand;
                    break;
                    
                case '/':
                val=first_operand/second_operand;
                break;
           }
           st.push(val);
        }else if(ch>='0'&& ch<='9'){
            st.push(ch-'0');
        }
    }
}

int main() {
    // Write C++ code here
   string str=("-+7*45+20");
   stack<int> st;
   convert(str,st);
   cout<<"eval is: "<<st.top()<<endl;

    return 0;
}