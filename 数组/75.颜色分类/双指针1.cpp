//相对单指针，时间要快，空间消耗要大

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //俩指针都是从头开始遍历
        int p0 = 0, p1 = 0;
        for(int i=0; i<n; i++){
            //如果nums[i] == 1,就将nums[i]和nums[p1]的位置交换，并将p1++
            //为何只增p1而不增p0？ 因为p0代表的是0这一数字，是要在p1后存放
            if(nums[i] == 1){
                swap(nums[i], nums[p1]);
                ++p1;
            }
            //如果nums[i] == 0,就将nums[i]和nums[p0]的位置交换，并将p1和p0都++
            //为何要将俩个指针都++呢？ 因为p0是最后的指针，已经将nums[p0]的位置放了0，导致p1只能向前不能在p0后
            else if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                //防止换到最后出现p0将排好的1给覆盖掉的情况，所以在p1的位置将覆盖掉的1再换回来
                if(p0 < p1){
                    swap(nums[i], nums[p1]);
                }
                //同时继续向前遍历
                ++p0;
                ++p1;
            }
        }
    }
};
