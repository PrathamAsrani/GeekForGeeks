class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        int i = 0, j = 1;
        while(j < a.size()){
            if(a[i] > a[j]){
                if(ans.first == a[i]){
                    ans.second++;
                    if(ans.second == k) return ans.first;
                }
                else{
                    ans.first = a[i];
                    ans.second = 1;
                    if(ans.second == k) return ans.first;
                }
            }else{
                if(ans.first == a[j]){
                    ans.second++;
                    if(ans.second == k) return ans.first;
                }
                else{
                    a[i] = a[j];
                    ans.first = a[j];
                    ans.second = 1;
                    if(ans.second == k) return ans.first;
                }
            }
            j++;
        }
        return ans.first;
    }
};