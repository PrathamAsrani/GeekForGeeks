class Solution {
public:
    vector<int> helper(string &s){
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++) freq[s[i]-'a']++;
        return freq;
    }
    vector<int> fun(vector<int> &a, vector<int> &b){
        vector<int> ans(26);
        for(int i = 0; i < 26; i++) ans[i] = min(a[i], b[i]);
        return ans;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> freq = helper(words[0]);
        int n = words.size();
        for(int i = 1; i < n; i++){
            vector<int> vec = helper(words[i]);
            freq = fun(freq, vec);
        }
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                ans.push_back(string(1, i+'a'));
                freq[i]--;
            }
        }
        return ans;
    }
};