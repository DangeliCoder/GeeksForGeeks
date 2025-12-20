class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        vector<int> arr2;
        unordered_map<int,int> swaps;
        set<int> vis;
        int c, el;
        
        arr2 = arr;
        sort(arr2.begin(), arr2.end());
        for (int i = 0;i < (int)arr.size();i++)
            swaps[arr[i]] = arr2[i];
        c = 0;
        for (int i = 0;i < (int)arr.size();i++)
            if (vis.find(arr[i]) == vis.end())
            {
                el = arr[i];
                vis.insert(el);
                while (swaps[el] != arr[i])
                {
                    c++;
                    el = swaps[el];
                    vis.insert(el);
                }
            }
        return c;
    }
};