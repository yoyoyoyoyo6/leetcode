class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++) {
            // 模拟实现一个哈希表
            vector<int> cnt(26);
            // 用于存放s中出现最多次的字符
            int maxFreq = 0;
            for(int j = i; j<s.size(); j++) {
                // 将字符中的字母转为int类型的数，cnt中当前遍历字符出现的次数
                cnt[s[j]- 'a']++;
                // 取得出现次数的最大值
                maxFreq = max(maxFreq, cnt[s[j] - 'a']);
                // 用于存放出现最少字符的次数
                int minFreq = s.size();
                // 遍历cnt数组，找到出现次数最少的字符次数
                for(int k = 0; k < 26; k++) {
                    // cnt[k]>0代表当前该位置有意义
                    if(cnt[k] > 0)
                        minFreq = min(minFreq, cnt[k]);
                }
                // 不断更新res的值
                res += maxFreq - minFreq;
            }
            
        }
        return res;
    }
};
