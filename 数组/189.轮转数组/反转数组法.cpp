class Solution {
public:
    //反转数组
    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        //步骤：先将nums数组全部反转，这样子原数组中需要翻转的子数组，就会跑到数组最前面
        //在将反转后的数组以k为界限，左右子数组分别反转
        //k与n取模的目的是减少重复的移动
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
