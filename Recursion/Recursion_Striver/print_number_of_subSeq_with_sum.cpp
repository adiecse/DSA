#include <iostream>
using namespace std;
#include<vector>



int printSeq(int ind,int arr[],int n,int s,int  sum){
  if(ind==n){
        if(s==sum){
            return 1;
        }else{
            return 0;
        }
     
    }


  s+=arr[ind];
  int left=printSeq(ind+1,arr,n,s,sum);

  s-=arr[ind];
  
  
  int right=printSeq(ind+1,arr,n,s,sum);
    
  return left+right;
  
}
int main() {
  int arr[]={1,2,1};
  int n=3;
  int sum=2;
  vector<int> ds;
  int num=printSeq(0,arr,n,0,sum);
  cout<<num<<endl;
}