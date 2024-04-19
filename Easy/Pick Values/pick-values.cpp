//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int pickValues(int arr[], int n) {
        // code here
        int sum, sum1, sum2, sum3, sum4;
        
        if (n < 4)
        {
            sum = arr[0];
            for (int i = 1;i < n;i++)
                if (arr[i] < sum)
                    sum = arr[i];
            return sum;
        }
        sum1 = arr[0];
        sum2 = arr[1];
        sum3 = arr[2];
        sum4 = arr[3];
        for (int i = 4;i < n;i++)
        {
            sum = min({sum1, sum2, sum3, sum4}) + arr[i];
            sum1 = sum2;
            sum2 = sum3;
            sum3 = sum4;
            sum4 = sum;
        }
        return min({sum1, sum2, sum3, sum4});
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.pickValues(arr, n);
        cout << ans << "\n";
    }
    return 0;
}



// } Driver Code Ends