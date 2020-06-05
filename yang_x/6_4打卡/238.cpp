class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        std::vector<int> ans(len, 1);
        int left = 1, right = 1;
        for (int i = 0, j = len - 1; i < len; ++i, --j){
            ans[i] = ans[i] * left;
            ans[j] = ans[j] * right;
            left = left * nums[i];
            right = right * nums[j];
        }
        return ans;
    }
};
