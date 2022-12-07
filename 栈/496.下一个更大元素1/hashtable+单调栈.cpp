class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        stack<int> stk;
        for(int i=nums2.size() - 1; i>=0; i--) {
            // 以nums2[i]中的元素作为遍历，因为要找到nums1中数字x的下一个更大元素，
            // x在nums2中也存在，所以可以通过以x为下标，找到单调栈中的下一个最大元素
            int num = nums2[i];
            // 构建单调栈
            while(!stk.empty() && num >= stk.top()) {
                stk.pop();
            }
            // 以num为键，存放栈顶的num元素的下一个最大元素
            hashmap[num] = stk.empty() ? -1 : stk.top();
            stk.push(num);
        }
        vector<int> ans(nums1.size());
        for(int i=0; i<nums1.size(); i++) {
            // 以nums1中的元素为键，查找哈希表中对应的下一个最大元素
            ans[i] = hashmap[nums1[i]];
        }
        return ans;
    }
};
