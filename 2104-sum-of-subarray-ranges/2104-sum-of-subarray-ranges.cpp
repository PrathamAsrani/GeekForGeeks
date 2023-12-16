class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long left[n], right[n];
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; i++){
            int cnt = 1;
            while(!st.empty() && st.top().first > arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            left[i] = cnt;
            st.push({arr[i], cnt});
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            int cnt = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            right[i] = cnt;
            st.push({arr[i], cnt});
        }
        while(!st.empty()) st.pop();
        
        long long int mi = 0;
        for(int i = 0; i < n; i++) mi += (arr[i] * left[i] * right[i]);
        
        for(int i = 0; i < n; i++){
            int cnt = 1;
            while(!st.empty() && st.top().first < arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            left[i] = cnt;
            st.push({arr[i], cnt});
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            int cnt = 1;
            while(!st.empty() && st.top().first <= arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            right[i] = cnt;
            st.push({arr[i], cnt});
        }
        
        long long int mx = 0;
        for(int i = 0; i < n; i++) mx += (arr[i] * left[i] * right[i]);
        
        return mx-mi;
    }
};