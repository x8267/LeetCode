class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 2){
            return nums[0];
        }

        int i = 0, j = 0;
        for(int index = 0; index < nums.size(); index++){
            if(index != nums[index]){
                i = index;
                j = index;
                break;
            }
        }
        while(true){
            i = nums[i];
            j = nums[nums[j]];
            if(i == j) break;
        }
        i = 0;
        while(true){
            i = nums[i];
            j = nums[j];
            if(i == j) break;
        }
        return i;
    }
};