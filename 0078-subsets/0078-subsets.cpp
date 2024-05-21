class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << n); i++){
            vector<int> sub;
            int bits = i, idx = n-1;
            while(bits){
                if(bits&1){
                    sub.push_back(nums[idx]);
                }
                bits >>= 1;
                idx--;
            }
            ans.push_back(sub);
        }
        return ans;
    }
};