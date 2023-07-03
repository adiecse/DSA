class Solution {
public:

    void printSeq(int ind, int target, vector<int>&arr, vector<int> &ds, vector<vector<int>> &ans ){
        if(ind>=arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
        return;
    
        }

        if(target>=arr[ind]){
            ds.push_back(arr[ind]);
            printSeq(ind, target-arr[ind], arr, ds, ans);
            ds.pop_back();    
        }

        printSeq(ind+1 ,target,arr,ds,ans);

        return ;
  
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans; 
        printSeq(0, target, candidates, ds, ans);
        return ans;
    }
};