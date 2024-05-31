class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
        unordered_map<int, int> umpp;
        for(auto &x: nums){
            umpp[x]++;
        }
        vector<int> ans;
        for(auto itr: umpp){
            if(itr.second == 1){
                ans.push_back(itr.first);
            }
        }
        return ans;
        */

        // find xor
        int xr = 0;
        for(auto &x: nums) xr ^= x;
        
        // find first set bit from LSB
        int bitNum = 0;
        while(1){
            if(xr & (1 << bitNum)) break;
            bitNum++;
        }

        // divide into even and odd group
        int even = 0, odd = 0;
        for(auto &x: nums){
            if(x & (1 << bitNum)) odd ^= x;
            else even ^= x;
        }

        if(even < odd) return {even, odd};
        return {odd, even};
    }
};