class Solution {
public:
    vector<int> prevSmaller(vector<int> arr, int n){
        vector<int> ps(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ps[i] = -1;
            else ps[i] = st.top();
            st.push(i);
        }
        return ps;
    }
    
    vector<int> nextSmaller(vector<int> arr, int n){
        vector<int> ns(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) ns[i] = n;
            else ns[i] = st.top();
            st.push(i);
        }
        return ns;
    }
    
    int maximalRectangle(vector<vector<char>>& M) {
        int ans = 0, n = M.size(), m = M[0].size();
        vector<int> hei(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                hei[j] += (M[i][j] == '0') ? (-hei[j]) : 1;
            }
            vector<int> ps = prevSmaller(hei, m), ns = nextSmaller(hei, m);
            for(int i = 0; i < m; i++) ans = max(ans, (ns[i] - ps[i] - 1) * hei[i]);
        }
        return ans;
    }
};