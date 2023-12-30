// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void convert(char postfix[],string infix,stack<string> &st){
    for(int i=0; postfix[i]!='\0';i++){
        char ch=postfix[i];
        if(!st.empty() && (ch=='+'||ch=='-'||ch=='/'||ch=='*')){
            //cout<<"Got the operator: "<<ch<<endl;
            string first_operand=st.top();
            //cout<<"second operand: "<<second_operand<<endl;
            st.pop();
            //cout<<"second_operand is: "<<second_operand<<endl;
            string second_operand=st.top();
            st.pop();
            string exp;
            //cout<<"first_operand is: "<<first_operand<<endl;
           switch(ch){
                case '+':
                    exp="("+second_operand+ch+first_operand+")";
                    //cout<<"val is addition: "<<val<<endl;
                    break;
            
                case '-':
                    exp="("+second_operand+ch+first_operand+")";
                    //cout<<"val is addition: "<<val<<endl;
                    break;    
                    
                case '*':
                    exp="("+second_operand+ch+first_operand+")";
                    //cout<<"val is addition: "<<val<<endl;
                    break;
                    
                case '/':
                    exp="("+second_operand+ch+first_operand+")";
                    //cout<<"val is addition: "<<val<<endl;
                    break;
           }
           st.push(exp);
           //cout<<"pushing string :"<<exp<<endl;
        }else{
            //string value(1, ch);  //converts char to string
            string value;
            value+=ch;
            //cout<<"pushing : "<<value<<endl;
            st.push(value);
        }
    }
}

int main() {
    // Write C++ code here 23+65++
   char postfix[]="ab*dc+/e*";
   string infix;
   stack<string> st;
   convert(postfix,infix,st);
    cout<<"Infix is: "<<st.top()<<endl;
    return 0;
}