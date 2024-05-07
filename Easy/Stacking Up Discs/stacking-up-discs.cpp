//{ Driver Code Starts
//initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    int StackingUpDiscs(int N,int R[],int H[]){
        //code here
        vector<pair<int,int>> D;
        vector<int> dp;

        for (int i = 0;i < N;i++)
            D.push_back(make_pair(R[i], H[i]));
        sort(D.begin(), D.end());
        for (int i = 0;i < N;i++)
            dp.push_back(D[i].second);
        for (int i = 1;i < N;i++)
            for (int j = 0;j < i;j++)
                if (D[j].first < D[i].first && D[j].second < D[i].second &&
                    (dp[j] + D[i].second) > dp[i])
                    dp[i] = dp[j] + D[i].second;
        return *max_element(dp.begin(), dp.end());
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