class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        vector<vector<int> > nums(grid.size(), vector<int> (grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j){
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = nums[i-1][j];
                if (j > 0)
                    left = nums[i][j-1];
                nums[i][j] = max(up, left) + grid[i][j]; 
            }
        }
        int ans = nums[grid.size() - 1][grid[0].size() - 1];
        return ans;
    }
};

//优化后，减小空间复杂度
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        vector<int> nums(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[i].size(); ++j){
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = nums[j];
                if (j > 0)
                    left = nums[j-1];
                nums[j] = max(up, left) + grid[i][j]; 
            }
        }
        int ans = nums[grid[0].size() - 1];
        return ans;
    }
};