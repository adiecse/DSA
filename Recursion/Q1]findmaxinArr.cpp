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

int main() {
  int arr[6] = {10, 14, 4, 22, 88, 42};
  int n = 6;
  int maxi = INT_MIN;
  findmax(arr, 6, 0, maxi);
  int max = maxi;
  cout << max << " " << endl;
  cout << max << endl;
}