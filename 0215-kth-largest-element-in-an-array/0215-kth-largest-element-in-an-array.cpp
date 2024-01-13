class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end(), greater<int> ());
        return arr[k-1];
    }
};