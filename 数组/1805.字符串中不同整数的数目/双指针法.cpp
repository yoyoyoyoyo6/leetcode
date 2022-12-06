class Solution {
public:
    int numDifferentIntegers(string word) {
        // 创建一个哈希集合，用于存放word出现的数字
        unordered_set<string> s;
        int n = word.size(), p1 = 0, p2;
        while (true) {
            // 如果p1小于字符串长度，并且当前字符不为数字，则p1向前继续遍历
            while (p1 < n && !isdigit(word[p1])) {
                p1++;
            }
            // 如果已经遍历完整个字符串，则直接结束循环
            if (p1 == n) {
                break;
            }
            // p2指向当前p1的位置，继续向后遍历，形成一个只有数字字符的窗口
            p2 = p1;
            // 如果为数字，则p2++
            while (p2 < n && isdigit(word[p2])) {
                p2++;
            }
            // p1指向的字符为0，则将0去除
            while (p2 - p1 > 1 && word[p1] == '0') { // 去除前导 0
                p1++;
            }
            // 拷贝word中p2到p1中的元素到哈希集合中
            s.insert(word.substr(p1, p2 - p1));
            // 让p1指向p2的位置继续向后遍历
            p1 = p2;
        }
        // return哈希集合中字符串的个数，即为最终结果
        return s.size();
    }
};
