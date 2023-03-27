#include <iostream>
#include <limits.h>
using namespace std;

void findmax(int arr[], int n, int i, int &maxi) {
  // base
  if (n <= i) {
    return;
  }

  // solve a case
  if (arr[i] > maxi) {
    maxi = arr[i];
  }

  // recursive
  findmax(arr, n, i + 1, maxi);
}

void findmin(int arr[], int n, int i, int &mini){
   //base case
   if(n<=i){
    return ;
   }

   //solve case 
   if(arr[i]<mini){
    mini=arr[i];
   }
  //cout<<mini<<endl;

   //recursion case
   findmin(arr, n, i + 1, mini);

}

int main() {
  int arr[6] = {10, 14, 4, 22, 88, 42};
  int n = 6;
  int maxi = INT_MIN;
  int mini = INT_MAX;
  findmax(arr, 6, 0, maxi);
  findmin(arr, 6, 0, mini);
  int max = maxi;
  int min = mini;
  cout <<"max is ->" << max << " " << endl;
  cout <<"min is ->" <<min << " " << endl;
  
}