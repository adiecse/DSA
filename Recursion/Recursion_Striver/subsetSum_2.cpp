#include<bits/stdc++.h> 
#include<vector>

void subset(int ind, vector<int> &arr,vector<int> &sets ,vector<vector<int>> &ans){
   if(ind==arr.size()){
    ans.push_back(sets);
   }

   arr.push_back(arr[ind]);
   subset(ind+1,arr,sets,ans);

   arr.pop_back();
   if(arr[ind]!=arr[ind+1]){
    subset(ind+1,arr,sets,ans);
   }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
}

int main(){

}