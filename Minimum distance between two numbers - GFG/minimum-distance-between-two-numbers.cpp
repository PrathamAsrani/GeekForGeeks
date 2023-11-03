//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // int mn = INT_MAX;
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         if((a[i] == x && a[j] == y) || (a[i] == y && a[j] == x) && abs(i-j) < mn){
        //             mn = min(mn, abs(i-j));
        //         }
        //         if(mn == 1) return mn;
        //     }
        // }
        // return mn == INT_MAX ? -1:mn;
        
        int mn = n, lastX = -1, lastY = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == x){
                lastX = i;
                if(lastY != -1) mn = min(mn, abs(i - lastY));
            }else if (a[i] == y){
                lastY = i;
                if(lastX != -1) mn = min(mn, abs(i - lastX));
            }
        }
        return (lastY == -1 || lastX == -1)? -1:mn;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends