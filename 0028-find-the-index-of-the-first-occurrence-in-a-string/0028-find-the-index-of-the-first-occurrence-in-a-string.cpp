class Solution {
public:
    vector<int> prefix_function(string str){
        int n = str.size();
        vector<int> pi(n, 0);
        for(int i = 1; i < n; i++){
            int j = pi[i-1];
            while(j > 0 && str[i] != str[j])
                j = pi[j-1];
            if(str[i] == str[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int strStr(string t, string s) {
        vector<int> prefix = prefix_function(s);
        int j = 0, i = 0;
        while(i < t.size()){
            if(t[i] == s[j]){
                i++;
                j++;
            }
            else{
                if(j!=0)
                    j = prefix[j-1];
                else 
                    i++;
            }
            if(j == s.size())
                return i-s.size();
        }
        return -1;
    }
};