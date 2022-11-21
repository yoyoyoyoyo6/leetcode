class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 创建一个哈希表，将strs中的字符串排序后作为键，当前遍历的strs字符串为值，
        // 因为排序后的字符串为键可能对应多个个值，所以值用string类型的value存放该些值
        unordered_map<string, vector<string>> mp;
        for(string& str : strs) {
            // 用一个临时变量作为遍历工具，不改变当前遍历的值
            string key = str;
            // 给key排序，作为有相同字符的字符串的统一的键
            sort(key.begin(), key.end());
            // 以str为值存入哈希表中
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            // ans存放键中的信息
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
