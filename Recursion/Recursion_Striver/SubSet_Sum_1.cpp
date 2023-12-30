//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void printSeq(int ind, int n, vector<int>arr, int sum ,vector<int> &vectsum){
          if(ind==n){
                // sum+=arr[ind];
                vectsum.push_back(sum) ;
                return;
          }
        
        
          printSeq(ind+1,n,arr,sum,vectsum);
          
         
          
          printSeq(ind+1,n,arr,sum+arr[ind],vectsum);
          
        //   d.pop_back();
        
    }
    

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>vectsum;
        
        
        printSeq(0,N,arr,0,vectsum);
        return vectsum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends