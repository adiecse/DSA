#include<iostream>
using namespace std;
int lastOcc(string str, int n, int key,int i,int pos){
  if(i>n){
    return pos;
  }

  if(str[i]=='d'){
    return lastOcc(str,n,key,i+1,i);
  }else{
    return lastOcc(str,n,key,i+1,pos);
  }
  
}

int main(){
  string str="abcddefg";
  int n=str.size();
  char key='d';
  int i=0;
  int pos=-1;
  int ans=lastOcc(str, n, key, i, pos);
  cout<<"Location is:"<<ans<<endl;
  
}