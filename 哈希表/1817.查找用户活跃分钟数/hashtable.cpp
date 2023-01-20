class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        // 由于同一个用户的每次执行操作的时间不重复计算,所以hashtable中times的位置使用set存放
        // set可以避免重复数出现
        unordered_map<int, unordered_set<int>> activeMinutes;
        for(auto &&log : logs) {
            int id = log[0], times = log[1];
            activeMinutes[id].emplace(times);
        }
        vector<int> answer(k);
        for(auto &&[_, minutes] : activeMinutes) {
        // 这句是使用了迭代器自动迭代，auto && 是万能引用，_是不赋予实际的值，就是忽略这个值。
        // minutes就是每次从unordered_map中取出的unordered_set<int>，也就是键的值

        // activeMinutes中的值为一个集合，集合的长度就为当前id的活跃分钟数（在某一分钟执行了一次操作），
        // 所以直接取当前遍历值的长度即可
            int activeCount = minutes.size();
            // 答案数组的下标从 1 开始，所以要对activeCount - 1
            answer[activeCount - 1]++;
        }
        return answer;
    }
};
