class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(auto v : nums) {
            sum += v;
        }
        long long diff = abs(sum - goal);
        return (diff + limit - 1) / limit;
    }
};
