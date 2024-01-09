class Solution {
public:
    string minWindow(string s, string t) {
        int cnt = 0;
        int hash[256] = {0};
        for(char c:t){
            if(hash[c] == 0)
                cnt++;
            hash[c]++;
        }
        
        int i = 0, ans = INT_MAX, start = 0;
        for(int j = 0; j < s.length(); j++){
            hash[s[j]]--;
            if(hash[s[j]] == 0)
                cnt--;
            
            while(cnt == 0){
                if(j-i+1 < ans){
                    ans = j-i+1;
                    start = i;
                }
                hash[s[i]]++;
                if(hash[s[i]] == 1)
                    cnt++;
                i++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};