class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char ch;
        for(int i=0; i<s.size(); i++) {
            ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else{
                char topch=st.top();
                if(!st.empty()){
                   if(topch=='(' && ch==')'){
                        st.pop();
                    }else if(topch=='{' && ch=='}'){
                        st.pop();
                    }else if(topch=='[' && ch==']'){
                        st.pop();
                    }
                    // }else{
                    //     return false;
                    // }
                }else{
                    return false; 
                }
            }
        }

        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};