#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int* arr, int s, int e){
  int mid=(s+e)/2;

  int len1=mid-s+1;
  int len2=e-mid;

  int* left=new int[len1];
  int* right=new int[len2];
  //need not to be necesary that array will always start with 0 it will starts from s
  int k=s;
  for(int i=0; i<len1; i++){
    left[i]=arr[k];
    k++;
  }

  k=mid+1;
  for(int i=0; i<len2; i++){
    right[i]=arr[k];
    k++;
  }
  //merging logic
  int leftIndex=0;
  int rightIndex=0;
  int mainArrayIndex=s;

  //pushing values by sorted way until one array gets ended
  while(leftIndex<len1 && rightIndex<len2){
    if(left[leftIndex]<right[rightIndex]){
      arr[mainArrayIndex++]=left[leftIndex++];
      // newArrayIndex++;
      // leftIndex++;
    }else{
      arr[mainArrayIndex++]=right[rightIndex++];
      // newArrayIndex++;
      // rightIndex++;
      
    }
  }

  //if left array ends up and values are left in right array
  while(rightIndex<len2){
    arr[mainArrayIndex++]=right[rightIndex++];
    // newArrayIndex++;
    // rightIndex++;
  }
  //if right array ends up and values are left in left array
  while(leftIndex<len1){
    arr[mainArrayIndex++]=left[leftIndex++];
    // newArrayIndex++;
    // leftIndex++;
  }
  
  
}

void mergesort(int* arr, int s,int e){
  int mid=(s+e)/2;

  //base condition
  if(s>=e){
    return;
  }

  //sort left side
  mergesort(arr,s,mid);

  //sort right side
  mergesort(arr,mid+1,e);

  merge(arr,s,e);
  
}

int main(){
  int arr[]={3,1,4,7,2};
  int n= 5;
  int s=0;
  int e=n-1;
  mergesort(arr,s,e);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}