class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<pair<bool, bool>> v(1001);
        for(auto &num: nums){
            if(num > 0){
                v[num].second = true;
            }else{
                v[abs(num)].first = true;
            }
        }
        int mx = -1;
        for(int i = 1; i <= 1000; i++){
            if(v[i].first and v[i].second){
                mx = i;
            }
        }
        return mx;
    }
};