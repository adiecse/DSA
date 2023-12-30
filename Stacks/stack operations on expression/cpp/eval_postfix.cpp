// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

void evaluate(char exp[],stack<int> &st){
    for(int i=0; exp[i]!='\0'; i++){
        char ch=exp[i];
        
        if(!st.empty() && (ch=='+'||ch=='-'||ch=='/'||ch=='*')){
            char second_op=st.top();
            st.pop();
            int second_operand=(second_op);
            cout<<"second_operand is: "<<second_operand<<endl;
            char first_op=st.top();
            st.pop();
            int  first_operand=(first_op);
            cout<<"first_operand is: "<<first_operand<<endl;
            int val=0;
           switch(ch){
                case '+':
                    val=first_operand+second_operand;
                    cout<<"val is addition: "<<val<<endl;
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
        }else if (ch >= '0' && ch <= '9'){
            int value=(ch-'0');
            cout<<"pushing : "<<value<<endl;
            st.push(value);
        }
    }
}

int main() {
    // Write C++ code here
    char str[100]="48*";
    stack<int> st;
    evaluate(str,st);
    cout<<"value is : "<<st.top()<<endl;
    return 0;
}