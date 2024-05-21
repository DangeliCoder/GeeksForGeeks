//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        multimap<pair<int,int>,int> boxes;
        vector<int> dp;
        int i, j;
        
        for (i = 0;i < n;i++)
        {
            boxes.insert(make_pair(make_pair(width[i], length[i]), height[i]));
            boxes.insert(make_pair(make_pair(length[i], width[i]), height[i]));
            boxes.insert(make_pair(make_pair(height[i], width[i]), length[i]));
            boxes.insert(make_pair(make_pair(width[i], height[i]), length[i]));
            boxes.insert(make_pair(make_pair(height[i], length[i]), width[i]));
            boxes.insert(make_pair(make_pair(length[i], height[i]), width[i]));
        }
        i = 0;
        dp.push_back(boxes.begin()->second);
        for (multimap<pair<int,int>,int>::iterator it2 = boxes.begin();it2 !=
            boxes.end();it2++)
        {
            if (it2 == boxes.begin())
                continue;
            i++;
            dp.push_back(it2->second);
            j = 0;
            for (multimap<pair<int,int>,int>::iterator it = boxes.begin();it != it2;
                it++)
            {
                if (it->first.first < it2->first.first &&
                    it->first.second < it2->first.second)
                    if ((it2->second + dp[j]) > dp[i])
                        dp[i] = (it2->second + dp[j]);
                j++;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends