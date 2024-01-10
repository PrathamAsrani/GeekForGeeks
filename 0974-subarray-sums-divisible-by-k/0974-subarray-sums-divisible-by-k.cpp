class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int, int> umpp;
        umpp[0] = 1;
        int sum = 0, ans= 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            sum %= k;
            if(sum < 0)
                sum += k;
            if(umpp.find(sum) != umpp.end()){
                ans += umpp[sum];
                umpp[sum]++;
            }
            else 
                umpp[sum] = 1;
        }
        return ans;
    }
};