class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        vector<int> ans;
        multiset<int> ms(nums1.begin(), nums1.end());
        for(auto &x: nums2){
            auto it = ms.find(x);
            if(it != ms.end()){
                ans.push_back(x);
                ms.erase(it);
            }
        }
        return ans;
        */

        vector<int> ans;
        unordered_map<int, int> freq;
        for(auto &x: nums1) 
            freq[x]++;
        for(auto &x: nums2){
            if(freq[x] > 0){
                freq[x]--;
                ans.push_back(x);
            }
        }
        return ans;
    }
};