class Solution {
public:
    int N;

    void helper(int node, vector<bool> &vis, vector<int> adj[], int &val, int depth){
        vis[node] = true;
        val += depth;
        for(auto v: adj[node]){
            if(!vis[v]){
                helper(v, vis, adj, val, depth+1);
            }
        }
    }

    int countNodes(int node, int par, int depth, vector<int> adj[], vector<int> &count, int &root_value){
        int total_cnt = 1;
        root_value += depth;
        for(auto nei: adj[node]){
            if(nei != par){
                total_cnt += countNodes(nei, node, depth+1, adj, count, root_value);
            }
        }
        count[node] = total_cnt;
        return total_cnt;
    }

    void ReRoot(int node, int par, vector<int> adj[], vector<int> &count, vector<int> &ans){
        for(auto nei: adj[node]){
            if(nei == par) continue;
            ans[nei] = ans[node] - count[nei] + (N - count[nei]);
            ReRoot(nei, node, adj, count, ans);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n, 0);
        /*
        // brute force
        for(int node = 0; node < n; node++){
            vector<bool> vis(n, false);
            int val = 0;
            helper(node, vis, adj, val, 0);
            ans[node] = val;
        }
        return ans;
        */

        // optimal
        // count the number of nodes, for each tree, and then use result[child] = result[par] - count[child] + N - count[child]

        vector<int> count(n, 0);
        N = n;
        int root_value = 0;
        countNodes(0, -1, 0, adj, count, root_value);
        ans[0] = root_value;
        ReRoot(0, -1, adj, count, ans);
        return ans;
    }
};