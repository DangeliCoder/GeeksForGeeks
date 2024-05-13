//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int a, b, res;
        
        a = 1;
        b = 1;
        if (n == 1)
            return a;
        if (n == 2)
            return b;
        n -= 2;
        while (n > 0)
        {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
            n--;
        }
        return res;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends