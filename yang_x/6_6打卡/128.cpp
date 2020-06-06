class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num;
        int len = 0;
        int cur = 0;
        for (const auto& i : nums){
            num.insert(i);
        }
        for (const auto& i : nums){
            if (!num.count(i-1)){
                cur = i;
                int curlen = 1;
                while (num.count(cur+1)){
                    cur++;
                    curlen++;
                }
                len = max(len, curlen);
            }
        }
        return len;
    }
};