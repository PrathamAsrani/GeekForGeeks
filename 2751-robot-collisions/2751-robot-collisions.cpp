typedef struct {
    int p;
    int h;
    char d;
    int idx;
} Robot;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hea, string dir) {
        stack<Robot> st;
        vector<Robot> v;
        int n = pos.size();

        for(int i = 0; i < n; i++){
            v.push_back({pos[i], hea[i], dir[i], i});
        }

        sort(v.begin(), v.end(), [&](Robot &a, Robot &b) {
            return a.p < b.p;
        });

        for(auto &it: v){
            bool equal = false;
            while(!st.empty() && st.top().d == 'R' && it.d == 'L'){
                if(st.top().h < it.h){
                    st.pop();
                    it.h--;
                } else if (st.top().h > it.h){
                    st.top().h--;
                    equal = true;
                    break;
                } else {
                    equal = true;
                    st.pop();
                    break;
                }
            }
            if(equal) continue;

            st.push({it.p, it.h, it.d, it.idx});
        }

        vector<int> ans(n, -1);
        while(!st.empty()){
            ans[st.top().idx] = st.top().h;
            st.pop();
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) {
                res.push_back(ans[i]);
            }
        }
        return res;
    }
};