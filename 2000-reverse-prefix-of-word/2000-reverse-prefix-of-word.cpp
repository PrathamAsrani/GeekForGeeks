class Solution {
public:
    string reversePrefix(string word, char ch) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int idx = word.find(ch);
        if(idx != -1) 
            reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};