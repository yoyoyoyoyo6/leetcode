// 如果一个密码满足以下所有条件，我们称它是一个 强 密码：

// 它有至少 8 个字符。
// 至少包含 一个小写英文 字母。
// 至少包含 一个大写英文 字母。
// 至少包含 一个数字 。
// 至少包含 一个特殊字符 。特殊字符为："!@#$%^&*()-+" 中的一个。
// 它 不 包含 2 个连续相同的字符（比方说 "aab" 不符合该条件，但是 "aba" 符合该条件）。
// 给你一个字符串 password ，如果它是一个 强 密码，返回 true，否则返回 false 。

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8) {
            return false;
        }
        unordered_set<char> specials = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        int n = password.size();
        bool hasLower = false, hasUpper = false, hasDight = false, hasSpecial = false;
        for(int i=0; i<n; i++) {
            if(i != n - 1 && password[i] == password[i+1]) {
                return false;
            }
            char ch = password[i];
            if(islower(ch)) {
                hasLower = true;
            }
            else if(isupper(ch)) {
                hasUpper = true;
            }
            else if(isdigit(ch)) {
                hasDight = true;
            }
            else if(specials.count(ch)) {
                hasSpecial = true;
            }
        }
        return hasLower && hasUpper && hasDight && hasSpecial;
    }
};
