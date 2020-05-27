class Solution {
public:
    bool isValid(string s) {
        stack<char> cstack;
        if (s.length() == 0)
            return true;
        if (s.length() % 2 == 1)
            return false;
        int i = 0;
        cstack.push(s[0]);
        map<char, char> cmap;
        cmap.insert(pair<char, char>{'(', ')'});
        cmap.insert(pair<char, char>{')', '('});
        cmap.insert(pair<char, char>{'[', ']'});
        cmap.insert(pair<char, char>{']', '['});
        cmap.insert(pair<char, char>{'{', '}'});
        cmap.insert(pair<char, char>{'}', '{'});
        ++i;
        for (i; i < s.length(); ++i){
            if (cstack.empty()){
                cstack.push(s[i]);
            }
            else {
                if (cmap[s[i]] == cstack.top()){
                    cstack.pop();
                }
                else
                    cstack.push(s[i]);
            }
        }
        if (cstack.empty())
            return true;
        return false;
    }
};