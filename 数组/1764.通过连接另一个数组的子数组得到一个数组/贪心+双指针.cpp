class Solution {
public:
    bool check(vector<int> &g, vector<int> &n, int k) {
        // k与g的当前行的元素个数的和要大于n的元素个数，则说明不满足匹配条件(没那么多元素给你匹配)
        // 直接return false
        if(k + g.size() > n.size()) {
            return false;
        }
        // 遍历g当前行元素
        for(int i=0; i<g.size(); i++) {
            // 如果g[i] != n[i+k]
            // 则为从nums数组当前遍历的起点开始的某一元素与g当前行元素的某个元素不相等
            // 则直接return false
            if(g[i] != n[i + k]) {
                return false;
            }
        }
        // 退出循环说明g的当前行的元素都与nums遍历起点后的某些元素相等,return true
        return true;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        // n == groups.size() 行数
        int i = 0;
        // k遍历nums数组中的元素，i遍历groups的行数
        for(int k = 0; k<nums.size() && i < groups.size();) {
            // 用check函数去判断当前groups[i]行是否与nums[k]后的元素相等
            if(check(groups[i], nums, k)) {
                // 相等，则k直接跳过当前行个元素
                k += groups[i].size();
                // 遍历下一行
                i++;
            }
            else {
                // 反之则遍历nums的下一个元素
                k++;
            }
        }
        // 如果i将行遍历完，则说明有n个相匹配的子数组，return true，反之return false
        return i == groups.size();
    }
};
