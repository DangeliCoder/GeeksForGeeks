//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<bool> visited;
    
    void aux_fun(vector<vector<int>> adj, int ind,
        vector<int> *res)
    {
        for (int i = 0;i < (int)adj[ind].size();i++)
            if (!visited[adj[ind][i]])
            {
                res->push_back(adj[ind][i]);
                visited[adj[ind][i]] = true;
                aux_fun(adj, adj[ind][i], res);
            }
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> res;
        
        visited.resize(adj.size(), false);
        res.push_back(0);
        visited[0] = true;
        aux_fun(adj, 0, &res);
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
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

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
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends