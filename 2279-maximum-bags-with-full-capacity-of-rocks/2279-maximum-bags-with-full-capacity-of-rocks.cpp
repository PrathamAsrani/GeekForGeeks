class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> bags;
        for(int i = 0; i < n; i++)
            bags.push_back(capacity[i] - rocks[i]);
        sort(bags.begin(), bags.end());
        // for(auto i:bags)
        //     cout << i << " ";
        // cout << "\n";
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(bags[i]){
                if(additionalRocks >= bags[i]){
                    additionalRocks -= bags[i];
                    bags[i] = 0;
                    // for(auto i:bags)
                    //     cout << i << " ";
                    // cout << "\n";
                }
            }
            if(bags[i] == 0){
                cnt++;
            }
        }
        return cnt;
    }
};