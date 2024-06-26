class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        // int n = S.length(), ans = 0;
        // for(int i = 0; i < n; i++){
        //     vector<bool> vis(256);
        //     for(int j = i; j < n; j++){
        //         int k = S[j];
        //         if(vis[k]) break;
        //         else{
        //             vis[k] = true;
        //             ans = max(ans, j-i+1);
        //         }
        //     }
        //     vis[S[i]] = false; // case of break;
        // }
        // return ans;
        
        
        int n = S.length(), ans = 0;
        int s = 0, e = 0;
        vector<bool> vis(256);
        while(e < n){
            while(vis[S[e]]) vis[S[s++]] = false;
            vis[S[e]] = true;
            ans = max(ans, e-s+1);
            e++;
        }
        return ans;
    }
};