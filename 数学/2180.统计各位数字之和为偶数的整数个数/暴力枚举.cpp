class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for(int i=1; i<=num; i++) {
            int x = i, sum = 0;
            while(x) {
                // 各位数字之和 是其所有位上的对应数字相加的结果
                // 让各位数字之和为偶数
                sum += x % 10;
                x /= 10;
            }
            if(sum % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};
