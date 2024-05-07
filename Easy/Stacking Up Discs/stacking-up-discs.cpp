//{ Driver Code Starts
//initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    vector<int> dp;
    
    int fun(int N,int R[],int H[], int prev, int i){
        if (i == N)
            return 0;
        if (dp[i] > 0)
            return dp[i];
            
            
        int res, aux;
        
        res = 0;
        for (int j = i;j < N;j++)
        {
            if (prev == -1)
            {
                aux = fun(N, R, H, j, j + 1) + H[j];
                if (aux > res)
                    res = aux;
                continue;
            }
            if (R[j] > R[prev] && H[j] > H[prev])
            {
                aux = fun(N, R, H, j, j + 1) + H[j];
                if (aux > res)
                    res = aux;
            }
        }
        dp[i] = res;
        return res;
    }
    
    public:
    int StackingUpDiscs(int N,int R[],int H[]){
        //code here
        vector<pair<int,int>> D;
        int R2[N], H2[N];

        for (int i = 0;i < N;i++)
            D.push_back(make_pair(R[i], H[i]));
        sort(D.begin(), D.end());
        for (int i = 0;i < N;i++)
        {
            R2[i] = D[i].first;
            H2[i] = D[i].second;
        }
        dp.resize(N, 0);
        return fun(N, R2, H2, -1, 0);
    }
};




//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int R[N],H[N];
        for(int i=0;i<N;i++)
         cin>>R[i]>>H[i];
         
        Solution ob;
        cout<<ob.StackingUpDiscs(N,R,H)<<endl; 
    }
}
// } Driver Code Ends