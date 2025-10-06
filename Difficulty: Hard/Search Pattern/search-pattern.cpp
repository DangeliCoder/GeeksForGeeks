class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector<int> pref_len, res;
        int i, j;
        
        pref_len.resize(pat.length(), 0);
        j = 0;
        for (i = 1;i < (int)pat.length();i++)
        {
            if (pat[i] == pat[j])
            {
                j++;
                pref_len[i] = j;
            }
            else
            {
                if (j > 0)
                {
                    j = pref_len[j - 1];
                    i--;
                }
            }
        }
        j = 0;
        i = 0;
        while (i < (int)txt.length())
        {
            if (pat[j] == txt[i])
            {
                j++;
                i++;
                if (j == (int)pat.length())
                {
                    res.push_back(i - j);
                    j = pref_len[j - 1];
                }
            }
            else
            {
                if (j > 0)
                    j = pref_len[j - 1];
                else
                    i++;
            }
        }
        return res;
    }
};