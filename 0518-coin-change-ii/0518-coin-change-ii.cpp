class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        int n = coins.size();
        for(int i = 0; i < n; i++){
            vector<int> curr(amount+1, 0);
            curr[0] = 1;
            for(int j = 1; j <= amount; j++){
                int notTake = dp[j];
                int take = 0;
                if(j >= coins[i]) take = curr[j-coins[i]];
                curr[j] = take+notTake;
            }
            dp = curr;
        }
        return dp[amount];
    }
};