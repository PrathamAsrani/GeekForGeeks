//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        set<int> ans;
        for(int i = 1;i <= sqrt(n); i++){
            if(n%i == 0){
                ans.insert(i);
                if(i != n/i) ans.insert(n/i);
            }
        }
        for(auto i: ans) cout << i<< " ";
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends