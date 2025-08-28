
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // Code here
        double exp_sum;
        int res;

        exp_sum = 0;
        for (int i = 0;i < (int)arr.size();i++)
            exp_sum += log10((double)arr[i]);
        res = (int)pow(10, exp_sum / (double)arr.size()) + 1;
        return res;
    }
};