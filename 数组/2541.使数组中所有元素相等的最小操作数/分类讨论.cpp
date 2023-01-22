class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        // neg 记录当nums1[i] < nums2[i]时的 sum(nums1[i] - nums2[i]) / k 的值
        // pos 记录当nums1[i] >= nums2[i]时的 sum(nums1[i] - nums2[i]) / k 的值
        long long neg = 0, pos = 0;
        for(int i=0; i<n; i++) {
            // 用det记录两数组对应元素的差值
            long long det = nums1[i] - nums2[i];
            // 第一个分类 k == 0 or k != 0
            if(k == 0) {
                // 当k == 0时并且两数组对应元素不相等，则直接return -1
                // 因为没办法通过加减使得两数组相同
                if(det != 0) {
                    return -1;
                }
            }
            // 当k != 0时，第二个分类 
            // 分两个类 det能被k整除 和 不能被k整除
            // 能被k整除时 分det >= 0 or det < 0
            else {
                // 不能被k整除，则说明不能通过n次变换使得nums1[i] == nums2[i]，直接return -1；
                if(det % k) return -1;
                // 当能被k整除时
                // 说明当前nums1[i]能通过n次变换使得nums1[i] == nums2[i]
                // det小于0时，使用neg存储n
                else if(det < 0) neg -= det / k;
                // 当det大于等于0时，使用pos存储n
                else pos += det / k;
            }
        }
        // 因为题目中的i和j是同时进行操作时，才能算一次操作数，所以i和j的使用次数肯定相同（i与j一一对应），
        // 即为neg肯定与pos相同
        // 不同直接return -1
        if(neg != pos) return -1;
        return pos;
    }
};
