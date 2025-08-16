class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int res, len;
        
        res = 0;
        len = (int)arr.size();
        for (int i = 0;i < len;i++)
            res += ((i + 1) * arr[i] * (len - i));
        return res;
    }
};