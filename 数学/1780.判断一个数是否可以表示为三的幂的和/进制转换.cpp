class Solution {
public:
    bool checkPowersOfThree(int n) {
        // 将n转为3进制，就可以将n拆分表示为三的幂
        while(n) {
            // 如果当前三进制位为2，则说明不满足三的幂这一条件
            if(n % 3 == 2) {
                return false; 
            }
            n /= 3; 
        }
        return true;  
    }
};
