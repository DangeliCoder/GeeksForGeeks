#User function Template for python3

class Solution:
    # Function to find uncommon characters between two strings.
    def uncommonChars(self, s1, s2):
        #code here
        res = set(s1 + s2)
        aux = []
        for c in res:
            if c in s1 and not c in s2:
                aux.append(c)
            if not c in s1 and c in s2:
                aux.append(c)
        aux.sort()
        res = ""
        for c in aux:
            res += c
        return res
