// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int precedancee(char ch){
    if(ch=='+'|| ch=='-'){
        return 2;
    }else if(ch=='*'|| ch=='/'){
        return 3;
    }else{
        return -1;
    }
}

string convert(string &infix,stack<char> &st){
    reverse(infix.begin(), infix.end());
    char prefix[100];
    int j=0;
    char top;
    for(int i=0; i<infix.length();i++){
        // cout<<"Input expression is "<<infix[i]<<endl;
        char ch = infix[i];
        if(ch==')'){
            // cout<<"Pushing ) in stack"<<endl;
            st.push(ch);
        }else if(ch=='('){
            while(st.top()!=')' && (!st.empty())){

              prefix[j]=st.top();
              j++;
            //   cout<<"Poping and printing "<<st.top()<<endl;
              st.pop();
              
               
            } 
            if(st.top()==')'){
               st.pop(); 
            }
            
        }else if((ch=='+'|| ch=='-' ||ch=='*'||ch=='/')){
            // cout<<"yes: "<<ch<<endl;
            // cout<<"precedancee(ch) : "<<precedancee(ch)<<endl;
            // if(!st.empty()){
            //     cout<<"precedancee(st.top()) : "<<precedancee(st.top())<<endl;
            // }    
            if(st.empty()){
                st.push(ch);
                // cout<<"pusing on stack: "<<ch<<endl;
            }else if(precedancee(ch)>precedancee(st.top())){
                st.push(ch);
                //cout<<"pusing on stack: "<<ch<<endl;
            }else if((precedancee(ch)==precedancee(st.top()))){
                st.push(ch);
                //cout<<"pusing on stack: "<<ch<<endl;
            
            }else if((precedancee(ch)<precedancee(st.top()))){
               // cout<<"came here with "<<ch<<endl;
                while((!st.empty())&&(precedancee(ch)<precedancee(st.top()))){
                    prefix[j]=st.top();
                    j++;
                    //cout<<"Printing : "<<st.top()<<endl;
                    st.pop();
                }
                st.push(ch);
            }
                    
            
        }else{
            //cout<<"printing char "<<ch<<endl;
            prefix[j]=ch;
            j++;
        }
        //cout<<"Current prefix is "<<prefix<<endl;
    }
    while (!st.empty()) {
        prefix[j++] = st.top();
        //cout<<"printing from left stack : "<<prefix<<endl;
        st.pop();
    }
    
    prefix[j] = '\0';
    return prefix;
    
    
}
int main() {
    // Write C++ code here
    stack<char> st;
    //"a+b*(c-d)/e"
    string infix="a+b*(c-d)/e";
    string prefix;
    prefix=convert(infix, st);
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " ;
    for(int i = prefix.length() - 1; i >= 0; i--)
    {
      	cout<<prefix[i];
    }
    return 0;
}