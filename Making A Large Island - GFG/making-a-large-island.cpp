//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DSU{
    public:
        int *rank, *parent, *size;
        DSU(int v){
            parent = new int[v+1];
            rank = new int[v+1];
            size = new int[v+1];
            for(int i = 0; i < v+1; i++){
                parent[i] = i;
                rank[i] = 0;
                size[i] = 1;
            }
        }
        
        int FindParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = FindParent(parent[node]);
        }
        
        void unioByRank(int s1, int s2){
            int p1 = FindParent(s1), p2 = FindParent(s2);
            if(p1 == p2) return ;
            if(rank[p2] > rank[p1]){
                parent[p1] = p2;
            }else if(rank[p1] > rank[p2]){
                parent[p2] = p1;
            }else{
                parent[p2] = p1;
                rank[p1]++;
            }
        }
        
        void unionBySize(int s1, int s2){
            int p1 = FindParent(s1), p2 = FindParent(s2);
            if(p1 == p2) return ;
            if(size[p1] < size[p2]){
                parent[p1] = p2;
                size[p2] += size[p1];
            }else{
                parent[p2] = p1;
                size[p1] += size[p2];
            }
        }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int delX[] = {0, -1, 0, 1};
        int delY[] = {-1, 0, 1, 0};
        DSU s(n*n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; k++){
                    int x = delX[k] + i;
                    int y = delY[k] + j;
                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1){
                        int s1 = i*n + j;
                        int s2 = x*n + y;
                        s.unionBySize(s1, s2);
                    }
                }
            }
        }
        
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int k = 0; k < 4; k++){
                    int x = delX[k] + i;
                    int y = delY[k] + j;
                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1){
                        components.insert(s.FindParent(x*n + y));
                    }
                }
                int maxSize = 0;
                for(auto itr:components){
                    maxSize += s.size[itr];
                }
                mx = max(maxSize+1, mx);
            }
        }
        
        for(int i = 0; i < n*n; i++) mx = max(mx, s.size[s.FindParent(i)]);
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends