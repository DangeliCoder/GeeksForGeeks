class Solution {

// Recursive function to check if a subset 
// with the given sum exists
int isSubsetSumRec(vector<int>& arr, int i, int sum,
                   vector<vector<int>> &memo, int part_sum) {
  
   	// If the sum is zero, we found a subset
   	if (part_sum == sum)
        return 1;

    // If no elements are left
    if (i == ((int)arr.size() - 1))
        return 0;

    // If the value is already
    // computed, return it
   	if (memo[i + 1][part_sum] != -1)
       	return memo[i + 1][part_sum];

    if ((part_sum + arr[i + 1]) > sum)
        return isSubsetSumRec(arr, i + 1, sum, memo, part_sum);;
    
    memo[i + 1][part_sum] = isSubsetSumRec(arr, i + 1, sum, memo, part_sum + arr[i + 1]) |
                        isSubsetSumRec(arr, i + 1, sum, memo, part_sum);;
    return memo[i + 1][part_sum];
}

public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int N, sum, res;
        
        N = (int)arr.size();
        sum = 0;
        for (int i = 0;i < N;i++)
            sum += arr[i];
        if (sum % 2 > 0)
            return false;
        sum /= 2;

        vector<vector<int>> memo(arr.size(), vector<int>(sum + 1, -1));
        res = isSubsetSumRec(arr, -1, sum, memo, 0);
        if (res > 0)
    	    return true;
        return false;
    }
};