#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;


bool BinarySearch(vector<int> &v, int start, int end,int key){
  if(start>end){
    return false;
  }

  int mid=(start+end)/2;
  if(v[mid]==key){
    return true;
  }
  //Recursive key<mid
  if(v[mid]>key){
    return BinarySearch(v,  start, (mid-1),key);
  }else{
    return BinarySearch(v,  (mid+1), end,key);
  }
}

int main() {
  vector<int>  v={2,4,6,8,10,12};
  int n=v.size();
  
  int start=0;
  int end=n-1;
  int key=21;
  bool KeyFound=BinarySearch(v,start,end,key);
  if(KeyFound){
    cout<<"Key Found"<<endl;
  }else{
    cout<<"Key not found"<<endl;
  }
  
}