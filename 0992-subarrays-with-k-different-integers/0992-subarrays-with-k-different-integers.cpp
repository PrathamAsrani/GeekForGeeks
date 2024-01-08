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
    
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        // O(2n)
        // return subarraysWithAtmostKDistinct(arr, k) - subarraysWithAtmostKDistinct(arr, k-1);
        
        // O(n)
        int s = 0, e = 0, prefix = 0, cnt = 0, n = arr.size();
        int ans = 0;
        unordered_map<int, int> umpp;
        while(e < n){
            umpp[arr[e]]++;
            if(umpp[arr[e]] == 1)
                cnt++;
            if(cnt > k){
                cnt--;
                prefix = 0;
                umpp[arr[s]]--;
                s++;
            }
            while(umpp[arr[s]] > 1){
                umpp[arr[s]]--;
                s++;
                prefix++;
            }
            if(cnt == k) 
                ans += prefix+1;
            e++;
        }
        return ans;
    }
};