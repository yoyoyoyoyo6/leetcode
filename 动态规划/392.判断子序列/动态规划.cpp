class Solution {
public:
    bool isSubsequence(string s, string t) {
        //dp[i][j] 表⽰以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，
        //相同⼦序列的长度为dp[i][j]。
        //以i-1和j-1的下标为结尾，方便初始化初始状态，相应的dp数组的长度也都要加一
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=t.size(); j++){
                //如果俩字符串当前的元素相同，相同⼦序列长度⾃然要在dp[i-1][j-1]的基础上加1
                //其实也等于暴力解法下的i++和j++
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i-1][j-1] + 1;
                //如果俩字符串当前遍历元素不相等，让t字符串继续遍历，相当于暴力解法中的不满足在相等条件时的j++
                else dp[i][j] = dp[i][j-1];
            }
        }
        //如果dp数组的最后一个元素(遍历到最后存放在dp中的值) == s字符串的长度，则说明遍历完了s字符串，也等价于找完了s字符串，直接return true
        if(dp[s.size()][t.size()] == s.size()) return true;
        //反之return false
        return false;
    }
};
