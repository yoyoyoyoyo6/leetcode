class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int curDistance = 0; //当前覆盖最远距离的元素的下标
        int ans = 0;  //记录走的最大步数
        int nextDistace = 0; //下一步覆盖最远距离的元素的下标
        //i为当前遍历的元素下标
        //当i遍历到nums.size() - 2时
        //如果移动下标等于当前覆盖最⼤距离下标， 需要再⾛⼀步（即ans++），因为最后⼀
         //     步⼀定是可以到的终点。
        //如果移动下标不等于当前覆盖最⼤距离下标，说明当前覆盖最远距离就可以直接达
            //到终点了，不需要再⾛⼀步
        for(int i=0; i<nums.size() - 1; i++){
            nextDistace = max(nums[i] + i, nextDistace);
            if(i == curDistace){
                ans++;
                curDistace = nextDistace;
            }
        }
        return ans;
    }
}
