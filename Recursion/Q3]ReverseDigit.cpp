#include <iostream>
#include <limits.h>
using namespace std;

void rev(int n) {
  // base
  if (n == 0) {
    
    return;
  }

  int newN = n / 10;
  int rem = n % 10;
  cout << rem<< " ";
  // Recursion
  rev(newN);


}

int main() {
  int n = 654;

  rev(n);
}