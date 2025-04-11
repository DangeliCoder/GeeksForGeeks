//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<bool> visited;
        queue<int> nodes;
        int node;
        vector<int> res;
        
        visited.resize(adj.size(), false);
        nodes.push(0);
        visited[0] = true;
        while (!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            res.push_back(node);
            for (int i = 0;i < (int)adj[node].size();i++)
                if (!visited[adj[node][i]])
                {
                    nodes.push(adj[node][i]);
                    visited[adj[node][i]] = true;
                }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends