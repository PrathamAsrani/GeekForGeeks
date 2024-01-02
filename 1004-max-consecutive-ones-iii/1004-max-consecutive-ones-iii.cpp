class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int ans = 0, s = 0, e = 0, cnt = 0, n = arr.size();
        while(e < n){
            if(arr[e] == 0) cnt++;
            while(cnt > k){
                if(arr[s] == 0) 
                    cnt--;
                s++;
            }
            ans = max(ans, (e-s+1));
            e++;
        }
        return ans;
    }
};