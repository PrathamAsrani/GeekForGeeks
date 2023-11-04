class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto i: left) ans = max(i, ans);
        for(auto i: right) ans = max(n-i, ans);
        return ans;
    }
};