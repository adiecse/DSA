#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void QuickSort(int arr[], int s, int e){
  int pivotIndex=s;
  int pivotele= arr[pivotIndex];
  int count=0;

  if(s>=e){
    return;
  }

  //counting smaller numbers;
  for(int i=s+1; i<=e; i++){
    if(arr[i]<pivotele){
      count++;
    }
  }
  
  //Replacing postion of comp with right position element
  int posi = s+count;
  swap(arr[posi],arr[pivotIndex]);
  pivotIndex=posi;

  int i=s;
  int j=e;

  while(i<pivotIndex && j>pivotIndex){
    while(arr[i]<arr[pivotIndex]){
      i++;
    }

    while(arr[j]>arr[pivotIndex]){
      j--;
    }

    if(i<pivotIndex && j>pivotIndex){
      swap(arr[i],arr[j]);
    }

    QuickSort(arr,s,(pivotIndex-1));

    QuickSort(arr,(pivotIndex+1),e);
    
  }

}

int main(){
  int arr[]={3,1,4,7,2};
  int n= 5;
  int s=0;
  int e=n-1;
  QuickSort(arr,s,e);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}