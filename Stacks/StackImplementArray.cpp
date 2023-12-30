// // Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;
// class stack{
//     public:
//     int* arr;
//     int size;
//     int top;
    
//     stack(int size){
//         this->size=size;
//         arr=new int[size];
//         top=-1;
//     }
    
//     void push(int data){
//       if(size-top>1){
//          top++;
//          arr[top]=data;
//        }else{
//           cout<<"stack overflow"<<endl;
//        }
//     }   
    
//     void pop(){
//         if(top>=0){
//             top--;
//         }else{
//             cout<<"Stack undrflow<<endl"<<endl;
//         }
//     }
    
//     void peek(){
//         if(top>=0  && top<size){
//             cout<<"Top element in Stack"<<arr[top]<<endl;
//         }else{
//             cout<<"No element exsist in stack"<<endl;
//         }
//     }
    
//     bool isEmpty(){
//         if(top==-1){
//             return true;
//         }else{
//             return false;
//         }
//     }
    
//     void print(int size){
//         for(int i=0; i<size; i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
 
// };





int main() {
    stack st(5);
    st.push(9);
    st.push(8);
    st.pop();
    st.peek();
    st.isEmpty();
    st.print(5);
    

    return 0;
}
