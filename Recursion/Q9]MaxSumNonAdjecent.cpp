#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int findMax(vector<int>& arr, int maxi,int i, int n){
  //base case
  if(i>n){
    return maxi;
  }

  //out case
  int out= findMax(arr,maxi,i+1,n);

  //in case
  int in= findMax(arr,maxi+arr[i],i+2,n);

  return max(out,in);
}

int main(){
  vector<int> arr={2,1,4};
  int maxi=0; //INT_MIN
  int i=0;
  int n=arr.size();
  int ans=findMax(arr,maxi,i,n);
  cout<<ans<<":is"<<endl;
  return 0;
}