#include <iostream>
#include <limits.h>
#include <vector>
#include<string.h>
using namespace std;

void PrintGrp(string str, string output, int i){
  //base case
  if(i>=str.length()){
    cout<<output<<endl;
    return;
  }

  //taking not
  PrintGrp(str,output,i+1);

  //taking in
  output=output+str[i];
  PrintGrp(str,output,i+1);
  

  
}

int main() {
 string str="abc";
 int i=0;
 string s="";
 PrintGrp(str, s,i);
 return 0;
}