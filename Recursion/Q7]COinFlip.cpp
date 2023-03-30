#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int mink(vector<int> &arr, int tar) {
  int mini = INT_MAX;
  if (tar == 0) {
    return 0;
  }

  if (tar < 0) {
    return INT_MAX;
  }

  for (int i = 0; i < arr.size(); i++) {
    int ans = mink(arr, tar - arr[i]);
    if (ans != INT_MAX) {
      mini = min(ans + 1, mini);
    }
  }
  return mini;
}

int main() {
  vector<int> v = {1, 2};
  int tar = 4;
  int n = v.size();
  int b = mink(v, tar);
  cout << b << endl;
}