class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int ans = 0, s = 0, e = 0, n = a.size();
        while(e < n){
            if(a[e] == 0){
                s = e+1;
            }
            ans = max(ans, (e-s+1));
            e++;
        }
        return ans;
    }
};