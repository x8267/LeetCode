class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = (j - i) * min(height[i], height[j]);
        while (i < j){
            int temp = (j - i) * min(height[i], height[j]);
            ans = max(ans, temp);
            if (height[i] < height[j])
                ++i;
            else 
                --j;
        }
        return ans;
    }
};