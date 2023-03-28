//Not Working for even number of members of array

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

bool BinarySearch(vector<int> &arr, int start, int end, int key) {
  // base case 1
  if (start > end) {
    return false;
  }
  // base case 2
  if (arr[start] == arr[end]) {
    return true;
  }
  int mid = (start + end) / 2;
  // key
  if (key > arr[mid]) {
    return BinarySearch(arr, (mid + 1), end, key);
  } else {
    return BinarySearch(arr, start, (mid - 1), key);
  }
}

int main() {
  int mini = 0;
  vector<int> arr = {7, 8, 10, 12, 18, 20,31};
  int n = arr.size();
  bool ElementFound = BinarySearch(arr, 0, (n - 1), 7);
  if (ElementFound) {
    cout << "Element Found" << endl;
  } else {
    cout << "Element not Found" << endl;
  }
}