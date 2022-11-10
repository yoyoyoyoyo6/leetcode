//相对于方法一，从p0和p1变为了p0和p2；从两个都从头开始遍历，变为了一个从头开始遍历，一个从尾部开始遍历；从找0和1变为了找0和2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //p0从头开始遍历，p2从尾部开始遍历
        int p0 = 0, p2 = nums.size() - 1;
        for(int i=0; i<=p2; ++i){
            //将2都扔到后面去，和nums[p2]交换
            while(i <= p2 && nums[i] == 2){
                swap(nums[i], nums[p2]);
                --p2;
            }
            //如果nums[i] == 0则直接和nums[p0]交换即可，并将p0继续向前
            if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                ++p0;
            }
        }
    }
};
