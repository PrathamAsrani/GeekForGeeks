class Solution {
public:
    int characterReplacement(string str, int k) {
        int n = str.size(), i = 0, mxFreq = 0, ans = 0;
        unordered_map<char, int> umpp;
        for(int j = 0; j < n; j++){
            umpp[str[j]]++;
            if(mxFreq < umpp[str[j]])
                mxFreq = umpp[str[j]];
            while(abs((j-i+1) - mxFreq) > k) 
                umpp[str[i++]]--;
            ans = max(ans, (j-i+1));
        }
        return ans;
    }
};