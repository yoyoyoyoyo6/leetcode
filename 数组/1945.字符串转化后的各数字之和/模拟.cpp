class Solution {
public:
    int getLucky(string s, int k) {
        string ans;
        // 将字符串s中的字母都转化为数字
        // 转换为数字字符放到ans中
        for(char ch : s) {
            // 如果不加一则从0开始
            ans += to_string(ch - 'a' + 1);
        }
        // 要拆解起码要两个字符，所以ans.size() > 1
        // i从1开始循环，也可以用while(k-- && ans.size() > 1),因为i在for循环中没啥作用
        for(int i = 1; i<=k && ans.size() > 1; i++) {
            int sum = 0;
            // 将ans中的字符转化为数字存放到sum中
            for(char ch : ans) {
                sum += ch - '0';
            }
            // 在将sum转化为数字字符存放到ans中
            ans = to_string(sum);
        }
        // stoi将n进制的字符串转化为十进制的数字
        return stoi(ans);
    }
};
