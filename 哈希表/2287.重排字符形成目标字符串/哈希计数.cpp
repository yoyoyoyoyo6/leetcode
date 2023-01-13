class Solution {
public:
    // 可以从 s 取出一些字符并将其重排，得到若干新的字符串。
    // 说明在s中出现的副本都是target中元素的不同排列组合
    int rearrangeCharacters(string s, string target) {
        int cnt1[26]{};
        int cnt2[26]{};
        // 将s中每个字符出现的次数记录到cnt1中
        for (char& c : s) {
            ++cnt1[c - 'a'];
        }
        // 将target中每个字符出现的次数记录到cnt2中
        for (char& c : target) {
            ++cnt2[c - 'a'];
        }
        // 形成的副本数一定不会超过 100，所以设置ans为100
        int ans = 100;
        // 遍历俩数组
        for (int i = 0; i < 26; ++i) {
            // 如果当前遍历字符在cnt2中出现过
            // 在只考虑当前遍历字符的条件下，cnt1[i] / cnt2[i]的结果就为能组成的最大副本数
            // 所以遍历完cnt1[i] / cnt2[i]的结果，取最小(最小的最大副本数，即为最终的最大副本数（短板）)
            // 最小的除数决定能形成完整的副本的个数
            if (cnt2[i]) {
                ans = min(ans, cnt1[i] / cnt2[i]);
            }
        }
        return ans;
    }
};
