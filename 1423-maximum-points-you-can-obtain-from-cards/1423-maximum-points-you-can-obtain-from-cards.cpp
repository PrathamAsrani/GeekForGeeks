class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        // sum_wnd: represents the window od elements which are not considered in our answer
        int n = arr.size(), wnd = n-k, sum_wnd = 0, i = 0;
        for(i = 0; i < wnd; i++) sum_wnd += arr[i];
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int ans = (totalSum - sum_wnd); // selected k cards from last
        int j = 0;
        for(i ; i<n; i++){
            sum_wnd -= arr[j++];
            sum_wnd += arr[i];
            ans = max(ans, totalSum - sum_wnd);
        }
        return ans;
    }
};