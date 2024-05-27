//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int minSteps(string S)
	{
	    // Your code goes here
	    vector<int> dp;
	    bool append;
	    
	    dp.push_back(0);
	    for (int i = 1;i <= (int)S.size();i++)
	    {
	        if (i % 2 == 0)
	        {
	            append = true;
	            for (int j = 0;j < (i / 2);j++)
	                if (S[j] != S[j + i / 2])
	                {
	                    append = false;
	                    break;
	                }
                if (append)
    	            dp.push_back(dp[i / 2] + 1);
                else
    	            dp.push_back(dp.back() + 1);
	        }
	        else
	            dp.push_back(dp.back() + 1);
	    }
	    return dp.back();
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
        Solution ob;
   		cout << ob.minSteps(s);

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends