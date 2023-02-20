//coding ninjas question
//https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473
#include <bits/stdc++.h> 
#include<stack>
bool findRedundantBrackets(string &s)
{ bool isRedudant;
  char ch;
  stack<char>st;
  for(int i=0;i<s.length();i++){
    ch=s[i];
    if(ch=='('|| ch=='+'||ch=='-'||ch=='*'||ch=='/'){
      st.push(ch);
    }else{
      if( ch==')'){
         isRedudant=true;

        while(st.top()!='('){
          char top=st.top();
          if(top=='+'|| top=='*'||top=='-'||top=='/'){
            isRedudant=false;
          }
          //st.pop();
          //st.pop();
        }
        if(isRedudant==true){
          return true;
        }
        st.pop();  
        //st.pop();
      }
      
    }
  }
  if(isRedudant==false){
    return false;
  
  }
}