#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

bool check(vector<int>& arr, int n, int i){
  //base case
  if(i==(n-1)){
    return true ;
  }
  
  //solve one case 
  if(arr[i]>arr[i+1]){
    return false;
  }
  //REcursive case (must use Retrun to get Responce in BooL)
  return check(arr,n,i+1);
  
  
  
  
}

int main(){
  int mini=0;
  vector<int> arr={12,17,15,16,17};
  bool isSorted= check(arr,5,0);
  if(isSorted){
    cout<<"Array is Sorted"<<endl;
  }else{
    cout<<"Array is not sorted"<<endl;
  }
  
  
}