class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        /*
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
        */
        
        int n = nums.size();
        vector<int> oddIndices;
        oddIndices.push_back(-1);

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 1) {
                oddIndices.push_back(i);
            }
        }

        oddIndices.push_back(n);

        int result = 0;

        for (int i = 1; i + k < oddIndices.size(); ++i) {
            int left = oddIndices[i] - oddIndices[i - 1];
            int right = oddIndices[i + k] - oddIndices[i + k - 1];
            result += left * right;
        }

        return result;
    }
};