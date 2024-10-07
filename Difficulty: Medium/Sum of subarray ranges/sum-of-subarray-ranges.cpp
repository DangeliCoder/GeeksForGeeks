//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to calculate the sum of subarray ranges
    long long subarrayRanges(vector<int> &arr) {
        long long res;
        int j;
        stack<int> s;

        res = 0;
        for (int i = 0; i < (int)arr.size(); ++i)
        {
            if (!s.empty())
                while (arr[s.top()] > arr[i])
                {
                    j = s.top();
                    s.pop();
                    if (s.empty())
                    {
                        res -= ((long long)arr[j] * (i - j) * (j + 1));
                        break;
                    }
                    res -= ((long long)arr[j] * (i - j) * (j - s.top()));
                }
            s.push(i);
        }
        while (!s.empty())
        {
            j = s.top();
            s.pop();
            if (s.empty())
            {
                res -= ((long long)arr[j] * ((int)arr.size() - j) * (j + 1));
                break;
            }
            res -= ((long long)arr[j] * ((int)arr.size() - j) * (j - s.top()));
        }
        for (int i = 0; i < (int)arr.size(); ++i)
        {
            if (!s.empty())
                while (arr[s.top()] < arr[i])
                {
                    j = s.top();
                    s.pop();
                    if (s.empty())
                    {
                        res += ((long long)arr[j] * (i - j) * (j + 1));
                        break;
                    }
                    res += ((long long)arr[j] * (i - j) * (j - s.top()));
                }
            s.push(i);
        }
        while (!s.empty())
        {
            j = s.top();
            s.pop();
            if (s.empty())
            {
                res += ((long long)arr[j] * ((int)arr.size() - j) * (j + 1));
                break;
            }
            res += ((long long)arr[j] * ((int)arr.size() - j) * (j - s.top()));
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.subarrayRanges(arr) << endl;
    }
}

// } Driver Code Ends