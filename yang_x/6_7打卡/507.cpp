class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0)
            return false;
        int mid_num = num / 2;
        int sum = 0;
        for (int i = 1; i <= mid_num; ++i){
            if (num % i == 0)
                sum += i;
        }
        return sum == num;
    }
};

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0)
            return false;
        int mid_num = num / 2;
        int sum = 0;
        for (int i = 1; i * i <= num; ++i){
            if (num % i == 0){
                sum += i;
                if (i * i != num)
                    sum += num / i;
            }
        }
        return sum == 2 * num;  //这个2*num是因为1*num = num
    }
};