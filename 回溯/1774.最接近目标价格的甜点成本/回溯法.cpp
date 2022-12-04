class Solution {
public:
    // 参数含义
    // toppingCosts数组，
    // p为遍历toppingCosts数组的工具，
    // curCost为选择配料后的结果，
    // res作为return的结果，通过res与target的距离和curCost与target的距离比较，找到离target最近的成本
    // target作为要查找的结果
    void dfs(const vector<int>& toppingCosts, int p, int curCost, int& res, const int target) {
        // 如果res当前距离target的距离要小于curCost距离target，
        // 则说明当前的res是满足条件的，直接结束当前函数递归
        if(abs(res - target) < curCost - target) {
            return;
        }
        // 如果当前res离target的距离要大于等于curCost离target的距离
        else if(abs(res - target) >= abs(curCost - target)) {
            // 如果大于，则将res缩短到curCost的位置
            if(abs(res- target) > abs(curCost - target)) {
                res = curCost;
            }
            // 如果等于，则res取curCost和res之中的最小值
            // 因为要取成本相对小的一种，所以取相同距离下的最小值
            else {
                res = min(res, curCost);
            }
        }
        // 将p作为遍历toppingCosts的工具，如果遍历完toppingCosts数组，则停止当前递归
        if(p == toppingCosts.size()) {
            return;
        }
        // 选两份配料
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, res, target);
        // 选一份配料
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p], res, target);
        // 不选配料
        dfs(toppingCosts, p + 1, curCost, res, target);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        // 用res作为return的结果，用baseCost中的最小值初始化
        int res = *min_element(baseCosts.begin(), baseCosts.end());
        // 遍历baseCost数组，通过遍历找到最合适的组合
        for(auto& b : baseCosts) {
            dfs(toppingCosts, 0, b, res, target);
        }
        return res;
    }
};
