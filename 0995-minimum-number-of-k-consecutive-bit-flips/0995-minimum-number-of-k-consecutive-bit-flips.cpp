class Solution {
public:
    int minKBitFlips(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = arr.size(), ans = 0;
        /*
        // brute force:= TC: O(N*K), SC:O(1)
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                if(i+k > n) 
                    return -1;
                
                ans++;
                for(int j = i; j < i+k; j++){
                    arr[j] = (arr[j] == 0) ? 1 : 0;
                }
            }
        }
        return ans;
        */

        vector<int> isFlipped(n);
        int flipped = 0;
        for(int i = 0; i < n; i++){
            if(i >= k)
                flipped ^= isFlipped[i-k];
            if(flipped == arr[i]){
                if(i+k > n) 
                    return -1;
                
                isFlipped[i] = 1;
                flipped ^= 1;
                ans++;
            }
        }
        return ans;
    }
};

