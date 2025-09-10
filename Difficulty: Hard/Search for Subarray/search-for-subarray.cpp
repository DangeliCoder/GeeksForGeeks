class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> pref, res;
        int j;
        
        pref.resize(b.size(), 0);
        j = 0;
        for (int i = 1;i < (int)b.size();i++)
        {
            if (b[i] == b[j])
            {
                j++;
                pref[i] = j;
            }
            else
                if (j > 0)
                {
                    j = pref[j];
                    i--;
                }
        }
        j = 0;
        for (int i = 0;i < (int)a.size();i++)
        {
            if (a[i] == b[j])
            {
                j++;
                if (j == (int)b.size())
                {
                    res.push_back(i - j + 1);
                    j = pref.back();
                }
            }
            else
                if (j > 0)
                {
                    j = pref[j];
                    i--;
                }
        }
        return res;
    }
};