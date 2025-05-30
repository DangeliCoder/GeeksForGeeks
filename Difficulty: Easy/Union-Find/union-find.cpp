


// User function Template for C++

class Solution {
    int find(int x, int par[])
    {
        while (par[x] != x)
            x = par[x];
        return x;
    }
    
  public:
    // Function to merge two nodes a and b.
    void union_(int a, int b, int par[], int rank1[]) {
        // code here
        if (rank1[a] > rank1[b])
            par[find(b, par)] = find(a, par);
        else if (rank1[a] < rank1[b])
            par[find(a, par)] = find(b, par);
        else
        {
            par[find(b, par)] = find(a, par);
            rank1[a]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[]) {
        // code here
        if (find(x, par) == find(y, par))
            return true;
        return false;
    }
};