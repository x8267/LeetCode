class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return 1;
        int curlen = 0;
        int maxlen = 0;
        map<char, int> pos;
        for (int i = 0; i < s.length(); ++i){
            int prepos = -1;
            if (pos[s[i]] != 0)
                prepos = pos[s[i]];
            if (prepos < 0 || i - prepos + 1 > curlen){
                curlen++;
            }
            else{
                if (curlen > maxlen)
                    maxlen = curlen;
                curlen = i - prepos + 1;
            }
            pos[s[i]] = i + 1;
        }
        if (curlen > maxlen)
            maxlen = curlen;
        return maxlen;
    }
};