//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int helper(int index, int n, string s, vector<int>&dp){
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];
        int minCost = INT_MAX;
        for(int i = index; i < n; i++){
            if(isPalindrome(s, index, i)){
                int cost = 1+helper(i+1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[index] = minCost;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n, -1);
        return helper(0, n, str, dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends