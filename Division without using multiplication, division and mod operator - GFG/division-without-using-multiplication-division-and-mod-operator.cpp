//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        if(divisor == -1 && dividend == 1<<31) return INT_MAX;
	    bool sign = ((dividend >= 0) == (divisor >= 0))? true:false;
	    dividend = abs(dividend);
	    divisor = abs(divisor);
	    int ans = 0;
	    while(dividend-divisor >= 0){
	    	int cnt = 0;
	    	while(dividend - (divisor << (1+cnt)) >= 0) cnt++;
	    	ans += 1<<cnt;
	    	dividend -= divisor<<cnt;
	    }
	    return (sign)? ans:-ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends