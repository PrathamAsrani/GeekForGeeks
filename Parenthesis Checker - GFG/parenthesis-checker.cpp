//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<char> st;
        for(char c:s){
            if(st.empty()) st.push(c);
            else if(c == '(' || c == '{' || c == '[') st.push(c);
            else {
              if (c == '}' and st.top() == '{') st.pop();
              else if (c == '}' and st.top() != '{') return false;
              else if (c == ')' and st.top() == '(') st.pop();
              else if (c == ')' and st.top() != '(') return false;
              else if (c == ']' and st.top() == '[') st.pop();
              else if (c == ']' and st.top() != '[') return false;
            }
        }
        if(st.empty() == false) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends