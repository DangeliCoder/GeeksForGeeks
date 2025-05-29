class Solution {
    unordered_map<int,int> par;
    
    int find(int coord)
    {
        if (par[coord] != coord)
            coord = find(par[coord]);
        return coord;
    }
    
    void union_coord(int x, int y)
    {
        par.emplace(x, x);
        par.emplace(y + 10001, y + 10001);
        par[find(x)] = find(y + 10001);
        par[find(y + 10001)] = find(x);
    }
    
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        unordered_set<int> groups;
        
        for (int i = 0;i < n;i++)
            union_coord(stones[i][0], stones[i][1]);
        for (unordered_map<int,int>::iterator it = par.begin();
                it != par.end();it++)
            groups.insert(find(it->first));
        return (n - (int)groups.size());
    }
};