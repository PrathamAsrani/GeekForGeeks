//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool knows(vector<vector<int>>& M, int i, int j) {
        return M[i][j];
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        if(n == 1 && M[0][0] == 0) return 0;
	   // stack<int> st;
	   // for(int i = 0; i < n; i++) st.push(i);
	   // int i = 0;
	   // while(i++ < n-1){
	   // 	int first = st.top();
	   // 	st.pop();
	   // 	int second = st.top();
	   // 	st.pop();
	   // 	if(knows(M, first, second)) st.push(second);
	   // 	else st.push(first);
	   // }
	   // return st.top();
	   bool flag = false;
	   for(int i = 0; i < n; i++) {
	       for(int j = 0; j < n; j++){
	           if(M[i][j]) {
	               flag = true;
	               break;
	           }
	       }
	   }
	   int cele = -1;
	   if(flag){
	    for(int i = 0; i < n; i++){
	        bool isCele = true;
	        for(int j = 0; j < n; j++){
	            if(i!=j && knows(M, i, j)) {
	                isCele = false;
	                break;
	            }
	        }
	        if(isCele) {
	            cele = i;
	            break;
	        }
	    }
	    if(cele != -1){
	        for(int i = 0; i < n; i++){
	            if(i != cele && M[i][cele] == false) return -1;
	        }
	    }
	   }
	   return cele;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends