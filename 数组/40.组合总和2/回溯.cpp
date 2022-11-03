class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& candidates, int target, int sum, vector<bool>& used, int strantIndex){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(path);
        }
        for(int i=strantIndex; i<candidates.size() && sum + candidates[i] <= target; i++){
            //如果条件改为used[i-1] == true,则会导致在对树枝遍历时，遇到重复元素会跳过，但我们要查重的是树层
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            sum += candidates[i];
            used[i] = true;
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, used, i+1);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool>used(candidates.size(), false);
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used, 0);
        return result;
    }
};
