// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void convert(char str[],stack<char> &st,char ret[]){
    
    
    int j=0;
    char top;
    for(int i=0; str[i]!='\0';i++){
        cout<<"inside for looop "<<str[i]<<endl;
        char ch = str[i];
        if(!st.empty() &&ch=='('){
            cout<<"Pushing ( in stack"<<endl;
            st.push(ch);
        }else if(!st.empty() &&ch==')'){
            top=st.top() ;
            while(top!='('){
              
              st.pop();
              ret[j]=top;
              j++;
              cout<<"Poping and pushing "<<top<<endl;
              top=st.top();
              
            } 
            st.pop();
        }else if((ch=='+'|| ch=='-' ||ch=='*'||ch=='/')){
            if(!st.empty() &&((ch=='+' && st.top()=='-')||(ch=='-' && st.top()=='+'))){
               top=st.top();
               cout<<"Pushed "<<top<<endl;
               ret[j]=top;
               j++;
               st.pop();
               st.push(ch);
               cout<<"leaving 1"<<endl;
            }else if(!st.empty() &&((ch=='*' && st.top()=='/')||(ch=='/' && st.top()=='*'))){
                top=st.top();
                cout<<"Pushed "<<top<<endl;
                ret[j]=top;
                j++;
                st.pop();
                st.push(ch);
                cout<<"Leaving 2"<<endl;
            }else{

                st.push(ch);
                cout<<"Leaving 3"<<endl;
            }
              
         
        }else{
            cout<<"Pushed "<<ch<<endl;
            ret[j]=ch;
            j++;
        }
    }
    while (!st.empty()) {
        ret[j++] = st.top();
        st.pop();
    }
    ret[j] = '\0';
    
}
int main() {
    // Write C++ code here
    stack<char> st;
    //"a+b*(c-d)/e"
    char infix[]="a+b*(c-d)/e";
    char postfix[100];
    convert(infix, st, postfix);
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
