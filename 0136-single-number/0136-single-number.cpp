class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans = arr[0], n = arr.size();
        for(int i = 1; i < n; i++) ans ^= arr[i];
        return ans;
    }
};