class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> umpp;
        int s = 0, e = 0;
        while(e < n){
            umpp[nums[e]]++;
            while(umpp.size() > k){
                umpp[nums[s]]--;
                if(umpp[nums[s]] == 0)
                    umpp.erase(nums[s]);
                s++;
            }
            ans += (e-s+1);
            e++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k-1);
    }
};