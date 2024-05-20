class Solution {
public:
    int subsetXORSum(vector<int>& nums, int idx = 0, vector<int> sub = {}) {
        if(idx >= nums.size()) {
            if(sub.empty()) return 0;
            int _xor = sub[0];
            for(int i = 1; i < sub.size(); i++) _xor ^= sub[i];
            return _xor;
        }
        sub.push_back(nums[idx]);
        int take = subsetXORSum(nums, idx+1, sub);
        sub.pop_back();
        int notTake = subsetXORSum(nums, idx+1, sub);
        return take+notTake;
    }
};