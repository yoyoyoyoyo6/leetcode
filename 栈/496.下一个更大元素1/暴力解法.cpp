class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(m);
        for(int i=0; i<m; i++) {
            int j = 0;
            // 找到和当前遍历元素nusm1[i]相同的nums2[j]
            while(j < n && nums2[j] != nums1[i]) {
                ++j;
            }
            // 以nums2中下标j的位置为起点，继续向后遍历
            int k = j + 1;
            // 找到下一个比nums[j]大的元素
            while(k < n && nums2[k] < nums2[j]) {
                ++k;
            }
        // 如果k == n，则说明没有找到下一个比nums2[j]大的元素，则return -1，
        // 反之则将当前下标为k的nums2中的元素return出来
            ans[i] = k < n ? nums2[k] : -1;
        }
        return ans;
    }
};
