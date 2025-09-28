class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector<int> pref_len, res;
        int i, j;
        
        pref_len.resize(pat.length(), 0);
        i = 1;
        j = 0;
        while (i < (int)pat.length())
        {
            if (pat[i] == pat[j])
            {
                j++;
                pref_len[i] = j;
                i++;
            }
            else
            {
                if (j > 0)
                    j = pref_len[j - 1];
                else
                    i++;
            }
        }
        i = 0;
        j = 0;
        while (i < (int)txt.length())
        {
            if (pat[j] == txt[i])
            {
                j++;
                if (j == (int)pat.length())
                {
                    res.push_back(i - j + 1);
                    j = pref_len[j - 1];
                }
                i++;
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