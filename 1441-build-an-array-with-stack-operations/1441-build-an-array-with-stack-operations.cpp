class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string> ans;
        unordered_map<int, bool> umpp;
        int mx = t[t.size()-1];
        for(auto i:t) umpp[i] = true;
        for(int i = 1; i <= n; i++){
            if(i == mx+1) break;
            if(umpp[i]){
                ans.push_back("Push");
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};