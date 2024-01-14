

class Solution {
public:
    int thirdMax(vector<int>& arr) {
        unordered_set<int> s;
        for(auto i:arr)
            s.insert(i);
        arr.resize(0);
        for(auto i:s)
            arr.push_back(i);
        sort(arr.begin(), arr.end(), greater<int>());
        if(arr.size() > 2)
            return arr[2];
        else 
            return arr[0];
    }
};