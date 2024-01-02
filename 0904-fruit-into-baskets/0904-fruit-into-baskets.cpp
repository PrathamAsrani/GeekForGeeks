class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int ans = 0, i = 0, n = arr.size();
        unordered_map<int, int> umpp;
        for(int j = 0; j < n; j++){
            umpp[arr[j]] = j;
            if(umpp.size() > 2){
                auto it = min_element(umpp.begin(), umpp.end(), [](const auto &a, const auto &b){
                    return a.second < b.second;
                });
                i = it->second+1;
                umpp.erase(it);
            }
            ans = max(j-i+1, ans);
        }
        return ans;
    }
};