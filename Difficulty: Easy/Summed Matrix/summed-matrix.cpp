//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        long long res;

        if (n < q / 2 || q == 1)
          return 0;
        if (n >= q)
          n = q - 1;
        res = 2 * n - q + 1;
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends