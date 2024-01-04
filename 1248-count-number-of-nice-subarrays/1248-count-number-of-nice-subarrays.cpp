class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &i:nums) i = (i%2 == 1) ? 1:0;
        int ans = 0, cnt1 = 0;
        unordered_map<int, int> umpp;
        for(auto i:nums){
            if(i) cnt1++;
            if(cnt1 == k) ans++;
            if(umpp.find(cnt1-k) != umpp.end())
                    ans += umpp[cnt1-k];
            umpp[cnt1]++;
        }
        return ans;
    }
};