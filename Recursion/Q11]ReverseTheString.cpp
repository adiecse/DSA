#include <iostream>
#include <string.h>
using namespace std;
void reverseString(string &str, int start, int end, string ans) {
  // base case
  // cout<<ans<<endl;
  if (start >= end) {
    cout << "reversed string is: " << ans << endl;
    return;
  }

  

  ans[end] = str[start];
  ans[start] = str[end];

  reverseString(str, start + 1, end - 1, ans);
}

int main() {
  string str = "abcd";
  string ans = str;
  int n = str.size();
  int start = 0;
  int end = n - 1;

  reverseString(str, start, end, ans);
}