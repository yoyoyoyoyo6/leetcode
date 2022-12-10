class Solution {
public:
    bool check(const vector<int> &a, const vector<int> &b) {
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto & v : cuboids) {
            sort(v.begin(), v.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
        });

        vector<int> memo(n, -1);
        function<int(int, int)> dfs = [&](int top, int index)->int {
            if (index == cuboids.size()) {
                return 0;
            }
            if (top != -1 && memo[top] != -1) {
                return memo[top];
            }
            int height = dfs(top, index + 1);
            if (top == -1 || check(cuboids[top], cuboids[index])) {
                height = max(height, cuboids[index][2] + dfs(index, index + 1));
            }
            if (top != -1) {
                memo[top] = height;
            }
            return height;
        };
        return dfs(-1, 0);
    }
};
