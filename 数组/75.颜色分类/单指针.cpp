//相对于双指针要多遍历一次，时间消耗相对多

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pre = 0;
        //第一次遍历将0放在最前面
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                swap(nums[i], nums[pre]);
                ++pre;
            }
        }
        //第二次遍历将1放在第一次遍历完的pre后面
        for(int i=pre; i<nums.size(); i++){
            if(nums[i] == 1){
                swap(nums[i], nums[pre]);
                ++pre;
            }
        }
    }
};
