//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int n)
    {
        int _n = n, i = 1, firstZero = -1;
        string s = "";
        while(_n){
            if(_n&1) s = '1'+s;
            else{
                s = '0'+s;
                if(firstZero == -1) firstZero = i;
            }
            i++;
            _n >>= 1;
        }
        if(firstZero == -1) return n;
        int size = s.size();
        s[size-firstZero] = '1';
        n = 0;
        for(int i = 0; i < size; i++){
            if(s[i] == '1'){
                n += (1<<(size-i-1));
            }
        }
        return n;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends