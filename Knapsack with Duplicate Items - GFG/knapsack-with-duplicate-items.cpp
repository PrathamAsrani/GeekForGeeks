//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, int j, int n, int val[], int wt[], vector<vector<int>> &dp){
        if( i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(wt[i] > j) return dp[i][j] = helper(i+1, j, n, val, wt, dp);
        
        int take = val[i]+helper(i, j-wt[i], n, val, wt, dp);
        int notTake = helper(i+1, j, n, val, wt, dp);
        return dp[i][j] = max(take, notTake);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
        return helper(0, W, N, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends