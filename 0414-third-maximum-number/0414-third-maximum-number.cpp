

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        /*
        unordered_set<int> s;
        for(auto i:arr)
            s.insert(i);
        arr.resize(0);
        for(auto i:s)
            arr.push_back(i);
        sort(arr.begin(), arr.end(), greater<int>());
        if(arr.size() > 2)
            return arr[2];
        else 
            return arr[0];
        */
        
        sort(nums.begin(),nums.end(), greater<int>());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return (nums.size() < 3) ? nums[0] : nums[2];
    }
};