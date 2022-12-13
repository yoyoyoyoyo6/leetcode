class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> cnt(26);
        // 将s中出现的字符都赋值为true
        for(auto &v : sentence) {
            cnt[v - 'a'] = true;
        }
        for(auto &c : cnt) {
            // 如果cnt中的元素有不为true，则说明没有出现，则不能补全26个英文字母，return false
            if(c == false) {
                return false;
            }
        }
        return true;
    }
};
