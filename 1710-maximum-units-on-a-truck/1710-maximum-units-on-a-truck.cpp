bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second > b.second;
}

// 50 10 28 27

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>> arr;
        int n = boxTypes.size();
        for(int i = 0; i < n; i++)
            arr.push_back({boxTypes[i][0], boxTypes[i][1]});
        sort(arr.begin(), arr.end(), cmp);
        int ans = 0;
        for(auto i:arr){
            if((truckSize-i.first) >= 0){
                ans += (i.first * i.second);
                truckSize -= i.first;
            }else{
                ans += (truckSize * i.second);
                truckSize = 0;
            }
        }
        return ans;
    }
};