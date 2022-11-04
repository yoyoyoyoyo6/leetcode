class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
      
        int curDistance = 0; //当前覆盖最远距离的元素的下标
      
        int ans = 0;  //记录走的最大步数
      
        int nextDistace = 0; //下一步覆盖最远距离的元素的下标
      
        //i为当前遍历的元素下标
        for(int i=0; i<nums.size(); i++){
            //更新下一步覆盖最远距离的元素下标
            nextDistace = max(nums[i] + i, nextDistace);
          
            //如果当前遍历的元素为覆盖最远距离的元素的下标
            if(i == curDistance){
              
                //如果此时覆盖最远距离的元素的下标不为终点元素的下标
                if(curDistance != nums.size() - 1){
                  
                    //让最大步数加一
                    ans++;
                  
                    //将下一步覆盖最远距离的元素的下标赋给当前覆盖最远距离的元素的下标
                    curDistance = nextDistace;
                  
                    //如果当前的下一步的覆盖最远距离的下标已经超出元素的最大元素下标，则直接break
                    if(nextDistace >= nums.size() - 1) break;
                }
              
                //如果 当前覆盖最远距离的元素的下标为最后一个元素的下标，则直接break，return ans即可
                else break;
            }
        }
        return ans;
    }
};
