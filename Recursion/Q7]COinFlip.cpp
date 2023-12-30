#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int MinFlip(vector<int>& arr,int tar){
  int mini=INT_MAX;
  if(tar==0){
    return 0;
  }

  if(tar <0){
    return INT_MAX;
  }

  for(int i=0; i<arr.size(); i++){
    int ans=MinFlip(arr,tar-arr[i]);
    if(ans!=INT_MAX){
      mini=min(mini,ans+1);
    }
  }
  return mini;
  
}

int main(){
  vector<int> v={1,2};
  int target=5;
  int ans=MinFlip(v,target);
  cout<<ans<<":is"<<endl;
}