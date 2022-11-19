class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hashtable[225] = {0};
        int left = 0;
        int right = 0;
        int maxCount = 0;
        while(right < s.size()) {
            if(hashtable[s[right]] != 0) {
                // 如果hashtable[s[right]]所对应的值要大于left，
                // 则说明找到了满足条件的下一个窗口的起点，则将left向前遍历，缩小窗口，让left指向right后
                if(hashtable[s[right]] > left) {
                    // 缩小窗口，将left指向right后
                    left = hashtable[s[right]];
                }
                // 让该hashtable[s[right]]的值增，防止不满足缩小窗口的条件但缩小了窗口，所以进行与else同样的操作
                hashtable[s[right]] = right + 1;
            }
            else {
                hashtable[s[right]] = right + 1;
            }
            // 取得最大窗口的长度
            maxCount = max(maxCount, right - left + 1);
            // 扩大窗口
            right++;
        }
        return maxCount;
    }
};
