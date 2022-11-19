class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        // set容器：set中每个元素的值都唯一，而且系统能根据元素的值自动进行排序
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i=0; i<s.size(); i++) {
            // 寻找最长子串思路：
            // 如果窗内元素满足条件，R向右扩大窗口，并更新最优结果
            // 如果窗内元素不满足条件，L向右缩小窗口

            // 套用在此题，则为不进while循环时(即为当前遍历元素在lookup中没有出现过)，
            //      将右窗口扩大(lookup.insert(s[i]))，并求该处窗口的长度(即为没有重复元素的子串的长度)

            // 进while循环时(即为当前遍历元素在lookup中出现过)，
            //      将窗口缩小(left++)，将lookup中最左边的元素删除
            while(lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i - left + 1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};
