class Solution {
public:
    int numberOfSubstrings(string s) {
        int a, b, c, ans = 0;
        a = b = c = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a') a = i;
            if(s[i] == 'b') b = i;
            if(s[i] == 'c') c = i;
            ans += (a!=-1 && b!=-1 && c!=-1) ? min({a, b, c}) + 1 : 0;
        }
        return ans;
    }
};