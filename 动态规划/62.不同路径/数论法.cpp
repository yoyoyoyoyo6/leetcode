//当为m*n的矩阵，无论怎么走，都肯定要走 m + n - 2步
//这m + n - 2步中，肯定有m - 1步是往下走的，可以转化为，给你m + n - 2个不同的数，随便取m - 1个数，有⼏种取法

class Solution {
public:
    int uniquePaths(int m, int n) {
        //分子
        long long numerator = 1;
        //分母
        int denominator = m - 1;
        //一共要比遍历的次数
        int count = m - 1;
        //无论怎么走的要走的步数
        int t = m + n - 2;
      
        while(count--){
            //分子的阶乘
            numerator *= (t--);
            //分母不为0, && 分子能整除分母
            while(denominator != 0 && numerator % denominator == 0){
                //让除后的值继续更新在numerator中
                numerator /= denominator;
                //让denominator--，更新分母的值，达到分母是m-1的效果
                denominator--;
            }
        }
        return numerator;
    }
};
