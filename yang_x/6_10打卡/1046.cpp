class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int nums[1001] = { 0 };
        int max_num = -1;
        for (auto& i : stones) {
            nums[i]++;
            max_num = max(max_num, i);
        }
        int ans = 0;
        int i = max_num;
        while (i) {
            if (nums[i] != 0) {
                if (nums[i] % 2 == 0) {
                    nums[i] = 0;
                    ans = 0;
                }
                else {
                    int j = i - 1;
                    while (j) {
                        if (nums[j] != 0)
                            break;
                        j--;
                    }
                    if (nums[j] % 2 == 1) {
                        nums[i - j]++;
                        nums[i] = 0;
                        nums[j]--;
                        ans = i - j;
                        i = max(i - j + 1, j);
                    }
                    else {
                        nums[i - j]++;
                        nums[i] = 0;
                        nums[j]--;
                        ans = i - j;
                        i = max(i - j + 1, j + 1);
                    }
                }
            }
            --i;
        }
        return ans;
    }
};