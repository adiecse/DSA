// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include<stack>
using namespace std;

void convert(string prefix, stack<string> &st){
    for(int i=prefix.length()-1;i>=0;  i--){
        char ch=prefix[i];
        
        if((!st.empty())&&(ch=='+'||ch=='-'||ch=='/'||ch=='*')){
            string first_operand=st.top();
            st.pop();
            string second_operand=st.top();
            st.pop();
            string val;
            switch(ch){
                case '+':
                    val="("+first_operand+"+"+second_operand+")";
                    //cout<<"val is addition: "<<val<<endl;
                    break;
            
                case '-':
                    val="("+first_operand+"-"+second_operand+")";
                    break;    
                    
                case '*':
                    val="("+first_operand+"*"+second_operand+")";
                    break;
                    
                case '/':
                    val="("+first_operand+"/"+second_operand+")";
                    break;
           }
           st.push(val);
        }else {
            string value;
            value=value+ch;
            st.push(value);
        }
    }
}

int main() {
    // Write C++ code here
   string str=("-+7*45+20");
   stack<string> st;
   
   convert(str,st);
   cout<<"expression is : "<<st.top()<<endl;

    return 0;
}