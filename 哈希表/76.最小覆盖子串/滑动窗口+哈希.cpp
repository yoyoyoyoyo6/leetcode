class Solution {
public:
    string minWindow(string s, string t) {
        //定义两个哈希表存放s字符串和t字符串中元素出现的次数
        unordered_map<char, int> hs, ht;
        //将t中的信息录入哈希表ht中
        for(int i=0; i<t.length(); i++) ht[t[i]]++;

        //定义一个存放return信息的字符串
        string ans;
        //i是右边界，j是左边界，cns是有效字符数
        for(int i=0, j=0, cnt=0; i<s.length(); i++){
            //如果hs[s[i]]中出现的次数要小于等于ht[s[i]]中出现的次数，则为有效字符
            if(++hs[s[i]] <= ht[s[i]]) cnt++;
            //左窗口滑动去除冗余字符,让hs[]中的每一个元素出现的次数都要小于等于ht[]中对应的元素出现的次数，
            //  才能得到最小的子串(每个元素只出现一次的最小范围)
            while(hs[s[j]] > ht[s[j]]) hs[s[j++]]--;
            //如果有效字符数等于t的字符串长度，则说明遍历完了
            if(cnt == t.length()) {
                //如果ans为空 or ans的长度要大于窗口的长度，则将ans字符串存放内容初始一下
                if(ans.empty() || ans.length() > i - j + 1) {
                    //substr函数：s.substr(pos, len) 包含s中从pos开始的len个字符的拷贝
                    ans = s.substr(j, i - j + 1);
                }
            }
        }
        return ans;
    }
};
