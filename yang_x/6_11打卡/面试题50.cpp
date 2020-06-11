class Solution {
public:
    char firstUniqChar(string s) {
        if (s.length() == 0)
            return ' ';
        if (s.length() == 1)
            return s[0];
        unordered_map<char, int> charnum;
        char ans = ' ';
        for (int i = 0; i < s.length(); ++i)
            charnum[s[i]]++;
        for (int i = 0; i < s.length(); ++i)
            if (charnum[s[i]] == 1){
                ans = s[i];
                break;
            }
        return ans;
    }
};