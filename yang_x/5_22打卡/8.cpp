class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0)
            return 0;
        int beg = 0;
        for (beg; beg < str.length(); ++beg){   //找到第一个不为空格的字符
            if (str[beg] != ' ')
                break;
        }
        if (beg == str.length())
            return 0;
        long int ans = 0;        //转换后的整型
        bool flag = true;   //判断正负
        if (str[beg] == '-'){
            flag = false;
            beg++;
        }
        else if (str[beg] == '+'){
            flag = true;
            beg++;
        }
        if (str[beg] == '-' || str[beg] == '+'){
            return 0;
        }
        for (beg; beg < str.length(); ++beg){
            if (str[beg] == ' ' || str[beg] > '9' || str[beg] < '0')
                break;
            if (ans * 10 > pow(2, 31) - 1 && flag == true)
                return pow(2, 31) - 1;
            if (ans * 10 > pow(2, 31) && flag == false)
                return -pow(2, 31);
            ans *= 10;
            ans = ans + (str[beg] - '0');
            if (ans > pow(2, 31) - 1 && flag == true)
                return pow(2, 31) - 1;
            if (ans > pow(2, 31) && flag == false)
                return -pow(2, 31);
        }
        if (flag == false)
            ans = 0 - ans;
        return static_cast<int>(ans);
    }
};