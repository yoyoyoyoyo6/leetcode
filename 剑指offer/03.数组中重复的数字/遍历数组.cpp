class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 创建一个哈希表，值为bool类型，键为int类型
        unordered_map<int, bool> map;
        // 遍历数组
        for(int num:nums){
            // 如果map[num] == true,则说明该元素在之前出现过，直接return false
            if(map[num]){
                return num;
            }
            // 将遍历的每一个的元素都的hashtable的value都赋值为true
            map[num] = true;
        }
        // 跳出循环则没有
        return -1;
    }
};
