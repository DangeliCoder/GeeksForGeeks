//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    int minSum(int arr[], int n){
        //Write your code here
        int dp[4], sum;
        
        if (n < 4)
        {
            sum = arr[0];
            for (int i = 1;i < n;i++)
                if (arr[i] < sum)
                    sum = arr[i];
            return sum;
        }
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = arr[2];
        dp[3] = arr[3];
        for (int i = 4;i < n;i++)
        {
            sum = min({dp[0], dp[1], dp[2], dp[3]}) + arr[i];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
            dp[3] = sum;
        }
        return min({dp[0], dp[1], dp[2], dp[3]});
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends