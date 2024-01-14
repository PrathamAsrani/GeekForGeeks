class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        vector<int> arr;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) arr.push_back(m[i][j]);
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};