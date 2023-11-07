class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        for(int i = 0; i < n; i++) time[i] = (double)dist[i]/(double)speed[i];
        sort(time.begin(), time.end());
        int cnt = 1, time_passed = 1;
        for(int i = 1; i < n; i++){
            if(time[i] - time_passed <= 0) return cnt;
            cnt++;
            time_passed++;
        }
        return cnt;
    }
};