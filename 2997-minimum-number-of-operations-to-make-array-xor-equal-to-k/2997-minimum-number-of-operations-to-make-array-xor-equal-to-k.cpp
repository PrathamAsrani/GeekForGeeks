class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        /*
        int ans = 0;
        vector<bool> v(32, false);
        vector<int> bit(32, 0);
        for(int i = 0; i < 32; i++){
            if(k & (1 << i)){
                v[i] = true;
            }
        }
        for(int i = 0; i < 32; i++){
            for(auto num: nums){
                if(num & (1 << i)){
                    bit[i]++;
                }
            }
        }
        for(int i = 0; i < 32; i++){
            if(v[i]){
                if(!(bit[i] & 1)){
                    ans++;
                }
            }else{
                if(bit[i] & 1){
                    ans++;
                }
            }
        }
        return ans;
        */

        int x = 0, ans = 0;
        for(auto num: nums) x ^= num;
        x ^= k;
        for(x; x > 0; x >>= 1){
            if(x&1) ans++;
        }
        return ans;
    }
};