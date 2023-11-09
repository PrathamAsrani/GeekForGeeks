class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.size(), ans = 0, len = 0;
        for(int i = 0; i < n; i++){
            if(i > 0 && s[i] == s[i-1]) len++;
            else len = 1;
            ans = (ans + len)%mod;
        }
        return ans;
    }
};