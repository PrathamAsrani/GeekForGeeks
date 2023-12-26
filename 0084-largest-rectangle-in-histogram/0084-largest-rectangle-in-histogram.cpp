class Solution {
public:
    vector<int> prevSmaller(vector <int> &arr, int n){
      stack<int> st;
      vector<int> ps(n);
      for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(st.empty()) ps[i] = -1;
        else ps[i] = st.top();
        st.push(i);
      }
      return ps;
    }
    
    
    vector<int> nextSmaller(vector <int> &arr, int n){
      stack<int> st;
      vector<int> ns(n);
      for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(st.empty()) ns[i] = n;
        else ns[i] = st.top();
        st.push(i);
      }
      return ns;
    }
    
    
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> ps = prevSmaller(arr, n), ns = nextSmaller(arr, n);
        int maxAns = 0;
        for(int i = 0; i < n; i++){
          int curr = (ns[i] - ps[i] - 1) * arr[i];
          maxAns = max(maxAns, curr);
        }
        return maxAns;
    }
};