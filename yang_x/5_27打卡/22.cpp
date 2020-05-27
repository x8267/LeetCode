class Solution {
public:
    void backtrace(vector<string> &ans, string& str, int open, int close, int n){
        if (str.size() == n * 2){
            ans.push_back(str);
            return;
        }
        if (open < n){
            str += '(';
            backtrace(ans, str, open + 1, close, n);
            str.pop_back();
        }
        if (close < open){
            str += ')';
            backtrace(ans, str, open, close + 1, n);
            str.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        backtrace(ans, str, 0, 0, n);
        return ans;
    }
};