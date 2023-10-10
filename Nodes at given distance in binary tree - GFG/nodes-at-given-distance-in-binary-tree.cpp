//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
public:
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        if(k == 0) return {target};
        Node *start = NULL;
        vector<int> ans;
        queue<Node *> q;
        unordered_map<int, Node*> umpp;
        q.push(root);
        umpp[-1] = root;
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            if(curr->data == target) start = curr;
            if(curr->left){
                umpp[curr->left->data] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                umpp[curr->right->data] = curr;
                q.push(curr->right);
            }
        }
        unordered_map<Node *, bool> visited;
        q.push(start);
        while(!q.empty()){
            if(k-- == 0) break;
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node *curr = q.front();
                q.pop();
                visited[curr] = true;
                int currData = curr->data;
                if(umpp[currData] != NULL && !visited[umpp[currData]]) q.push(umpp[currData]);
                if(curr->left && !visited[curr->left]) q.push(curr->left);
                if(curr->right && !visited[curr->right]) q.push(curr->right);
            }
        }
        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();
            ans.push_back(curr->data);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends