#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int MaxParts(vector<int> arr, int tar) {
  int maxi = INT_MIN;
  if (tar == 0) {
    return 0;
  }
  // if (tar < 0) {
  //   return INT_MIN;
  // }

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] != arr[i - 1]) {
      if(arr[i]<=tar){
        int ans = MaxParts(arr, tar - arr[i]);
        if (ans != INT_MIN) {
          maxi = max(ans + 1, maxi);
        }
      }  
    }
  }
  return maxi;
}

int main() {
  vector<int> arr = {7, 2, 2};
  int target = 7;
  int ans = MaxParts(arr, target);
  if (ans==INT_MIN){
    ans=0;
  }  
  cout << "Max parts are:" << ans << endl;
}