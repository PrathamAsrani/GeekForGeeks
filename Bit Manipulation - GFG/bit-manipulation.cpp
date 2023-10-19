//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        bitset<32> bSet(num);
        cout << bSet[i-1] << " ";
        bSet[i-1] = 1;
        cout << bSet.to_ullong() << " ";
        bSet[i-1] = 0;
        cout << bSet.to_ullong();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends