//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int n) {
        // code here
        vector<long long> dp(n);
        long long max;
        
        dp[1] = 1;
        for (int n2 = 2;n2 < n;n2++)
        {
            max = n2;
            for (int i = 1;i <= (n2 / 2);i++)
                if ((dp[i] * dp[n2 - i]) > max)
                    max = dp[i] * dp[n2 - i];
            dp[n2] = max;
        }
        max = 0;
        for (int i = 1;i <= (n / 2);i++)
            if ((dp[i] * dp[n - i]) > max)
                max = dp[i] * dp[n - i];
        return max;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.maxProduct(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends