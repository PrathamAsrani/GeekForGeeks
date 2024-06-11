class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> umpp;
        vector<int> ans;
        for(auto &num: arr1) umpp[num]++;
        for(auto &num: arr2){
            ans.insert(ans.end(), umpp[num], num);
            umpp.erase(num);
        }
        for(auto &itr: umpp) ans.insert(ans.end(), itr.second, itr.first);
        return ans;
    }
};