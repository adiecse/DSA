#include <iostream>
using namespace std;
#include<vector>



bool printSeq(int ind, vector<int> &ds, int arr[], int n, int s, int  sum){
  if(ind==n){
    if(s==sum){
      for(auto it:ds){
        cout<<it<<" "; 
      }
      cout<<endl;
      return true;
    }else{
      return false;
    }         
  }


  ds.push_back(arr[ind]);

  s+=arr[ind];
  if(printSeq(ind+1,ds,arr,n,s,sum)==true){
    return true;
  }
  s-=arr[ind];
  ds.pop_back();
  
  if(printSeq(ind+1,ds,arr,n,s,sum)==true){
    return true;
  }
  return false;
  
}
int main() {
  int arr[]={1,2,1};
  int n=3;
  int sum=2;
  vector<int> ds;
  printSeq(0,ds,arr,n,0,sum);
}