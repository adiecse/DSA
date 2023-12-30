#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int mink(vector<int>arr, int tar){
  int mini=INT_MAX;
  if(tar==2){
    return 0;
  }

  if(tar>2){
    return INT_MAX;
  }

  for(int i=0;i<arr.size();i++){
    int ans=mink(arr,tar+arr[i]);
    if(ans!=INT_MAX){
      mini=min(mini,ans+1);
    }
  }
  return mini;
}


int main() {
  vector<int> arr = {1, 2};
  int target=0;
  int ans=mink(arr,target);
  cout<<ans<<"is"<<endl;
}