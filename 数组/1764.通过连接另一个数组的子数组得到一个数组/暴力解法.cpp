class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), m = groups.size(), i, j, k = 0;
        for(i = 0; i < m;){
            int l = groups[i].size();
          
            if(k + l > n) return false;
          
            for(j = 0; j < l; j++) if(nums[k + j] != groups[i][j]) break;//尝试匹配
            
            // 跳出了循环，并且groups当前行元素与nums[k]后的某些元素匹配上了
            if(j == l) i++, k += l;//匹配成功
          
            else k++;//匹配失败
        }
        return true;
    }
};
