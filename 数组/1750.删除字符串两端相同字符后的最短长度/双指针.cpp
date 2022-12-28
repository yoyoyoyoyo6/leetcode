class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        // 类似前后的消消乐
        while (left < right && s[left] == s[right]) {
            char c = s[left];
            // 找几个相同的前缀
            while (left <= right && s[left] == c) {
                left++;
            }
            // 找与前缀内容相同的后缀相消
            while (left <= right && s[right] == c) {
                right--;
            }
        }
        // 当前后缀元素不相同时，则说明在right与left之间形成的窗口之间的字符串的前后缀不能相消
        return right - left + 1;
    }
};
