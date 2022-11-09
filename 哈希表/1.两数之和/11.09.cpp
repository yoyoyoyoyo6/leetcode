class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //创建一个哈希表hashtable
        unordered_map<int, int> hashtable;
        //遍历数组nums
        for(int i=0; i<nums.size(); i++){
            //auto被解释为一个自动存储变量的关键字，也就是申明一块临时的变量内存
            //find()函数，如果括号中的数在哈希的键中，如果有，则返回该数的位置，如果没有，则返回hashtable.end();
            auto it = hashtable.find(target - nums[i]);
            //it不等于hashtable.end()则说明(target - nums[i])在key中出现过
            if(it != hashtable.end()){
                //return 哈希值value
                return {it->second, i};
            }
            //将nums[i]作为键，i作为值存放到哈希表中
            hashtable[nums[i]] = i;
        }
        //如果都不满足，则return 空
        return {};
    }
};

// 假设target = nums[a] + nums[i];
// target - nums[i] = b;
// b没有在哈希表中的键中出现过，则将key = nums[i]  value = i;
// target - nums[a] = c;
// 如果b == nums[a] and c == nums[i](c在key中出现过)
// 则直接可得到target = nums[a] + nums[i];

// 步骤
// 遍历数组 nums，i 为当前下标，每个值都判断map中是否存在 target-nums[i] 的 key 值
// 如果存在则找到了两个值，如果不存在则将当前的 (nums[i],i) 存入 map 中，继续遍历直到找到为止
// 如果最终都没有结果则抛出异常
