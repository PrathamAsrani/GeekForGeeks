class Solution {
public:
    int countTriplets(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        /*
        // brute force O(N^4)
        int n = arr.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j; k < n; k++){
                    int a = 0, b = 0;
                    for(int l = i; l < j; l++){
                        a ^= arr[l];
                    }
                    for(int l = j; l <= k; l++){
                        b ^= arr[l];
                    }
                    if(a == b){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
        */

        /*
        // Slightly optimized using prefix array 
        // TC: O(N^3)
        int n = arr.size(), cnt = 0;
        vector<int> ps(n);
        ps[0] = arr[0];
        for(int i = 1; i < n; ps[i] = arr[i]^ps[i-1], i++);
        for(int i = 0; i < n; i++) cout << ps[i] << " ";
        cout << "\n";
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j; k < n; k++){
                    int a = ps[j-1];
                    if(i > 0) a ^= ps[i-1];
                    int b = ps[k] ^ ps[j-1];
                    if(a == b){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
        */

        /*
        // if the subarray from i to k xor is 0 then 
        // j can be placed at anywhere from (i+1 >= j <= k) therefore total valid subarrays are (k-i)
        // TC: O(N^2)
        int n = arr.size(), cnt = 0;
        vector<int> ps(n);
        ps[0] = arr[0];
        for(int i = 1; i < n; ps[i] = arr[i]^ps[i-1], i++);
        for(int i = 0; i < n; i++){
            for(int k = i+1; k < n; k++){
                int xr = ps[k];
                if(i > 0) xr ^= ps[i-1];
                if(xr == 0){
                    cnt += (k-i);
                }
            }
        }
        return cnt;
        */

        // dependency of prefix array is removed
        int n = arr.size(), cnt = 0;
        for(int i = 0; i < n; i++){
            int xr = arr[i];
            for(int k = i+1; k < n; k++){
                xr ^= arr[k];
                if(xr == 0){
                    cnt += (k-i);
                }
            }
        }
        return cnt;
    }
};