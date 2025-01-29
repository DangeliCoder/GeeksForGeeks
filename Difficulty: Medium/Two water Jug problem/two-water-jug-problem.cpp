//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int fun(int fromCap, int toCap, int d)
    {
        int op;
        int from, to, water;
        
        op = 1;
        from = fromCap;
        to = 0;
        while (from != d && to != d)
        {
            if (from == 0)
            {
                from = fromCap;
                op++;
            }
            if (to == toCap)
            {
                to = 0;
                op++;
            }
            water = min(from, toCap - to);
            from -= water;
            to += water;
            op++;
        }
        return op;
    }
    
    int gcd(int a, int b)
    {
        int c;
        
        if (a < b)
            swap(a, b);
        c = b;
        while (a % c != 0)
        {
            c--;
            while (b % c != 0)
                c--;
        }
        return c;
    }
    
	public:
	int minSteps(int m, int n, int d)
	{
	    // Code here
	    if (d > m && d > n)
	        return -1;
	    if (d % gcd(m, n) != 0)
	        return -1;
        return min(fun(m, n, d), fun(n, m, d));
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends