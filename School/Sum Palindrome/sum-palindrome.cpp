//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    long long reversedNumber(long long n)
    {
        int p10;
        long long digit;
        long long res;
        
        p10 = (int)log10(n);
        res = 0;
        for (int c = 1;c <= (p10 + 1);c++)
        {
            digit = (n % (long long)pow(10, c)) / (long long)pow(10, c - 1);
            res += (digit * (long long)pow(10, p10 - c + 1));
        }
        return res;
    }
    
  public:
    long long isSumPalindrome(long long n){
        // code here
        long long rev_n;
        int c;
        
        c = 0;
        rev_n = reversedNumber(n);
        while (rev_n != n && c <= 5)
        {
            n += rev_n;
            c++;
            rev_n = reversedNumber(n);
        }
        if (c > 5)
            return -1;
        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution ob;
        cout<<ob.isSumPalindrome(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends