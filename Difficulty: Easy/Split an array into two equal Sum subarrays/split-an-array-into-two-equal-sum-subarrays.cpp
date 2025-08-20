class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int tot, sum;
        
        tot = accumulate(arr.begin(), arr.end(), 0);
        if (tot % 2 != 0)
            return false;
        sum = 0;
        for (int i = 0;i < (int)arr.size();i++)
        {
            sum += arr[i];
            if (sum == (tot / 2))
                return true;
        }
        return false;
    }
};
