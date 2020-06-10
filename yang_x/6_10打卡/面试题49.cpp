class Solution {
public:
    int Min(int x, int y, int z){
        int min_num = min(x, y);
        return min(min_num, z);
    }
    int nthUglyNumber(int n) {
        if (n <= 0)
            return 0;
        vector<int> UglyNum(n, 0);
        UglyNum[0] = 1;
        int next_Ugly_pos = 1;
        int mult2 = 0;
        int mult3 = 0;
        int mult5 = 0;
        while (next_Ugly_pos < n){
            int min_Ugly = Min(UglyNum[mult2] * 2, UglyNum[mult3] * 3, UglyNum[mult5] * 5);
            UglyNum[next_Ugly_pos] = min_Ugly;
            while (UglyNum[mult2] * 2 <= UglyNum[next_Ugly_pos])
                ++mult2;
            while (UglyNum[mult3] * 3 <= UglyNum[next_Ugly_pos])
                ++mult3;
            while (UglyNum[mult5] * 5 <= UglyNum[next_Ugly_pos])
                ++mult5;
            ++next_Ugly_pos;
        }
        int ans = UglyNum[n - 1];
        return ans;
    }
};