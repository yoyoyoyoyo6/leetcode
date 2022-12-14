class Solution {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        for (auto &c : cuboids)
            sort(c.begin(), c.end());
        // 对begin排序的目的是为了长方体子序列能从左到右的顺序进行堆叠，保证状态转移的正确性
        // cuboids[j][0] <= cuboids[i][0] 恒成立
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size(), f[n];
        // 遍历所有长方体
        for (int i = 0; i < n; ++i) {
            f[i] = 0;
            // 遍历所有在i长方体之下的所有长方体
            for (int j = 0; j < i; ++j)
                // 排序后，cuboids[j][0] <= cuboids[i][0] 恒成立
                // 得到能堆叠到cuboids[i]上的长方体cuboids[j]
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                    // f[i]是得到最上面长方体的高
                    f[i] = max(f[i], f[j]); // cuboids[j] 可以堆在 cuboids[i] 上
            // 让f[i]加上当前遍历的cuboids[i]的高度
            f[i] += cuboids[i][2];
        }
        // return f数组中的最大元素，即为最大的高
        return *max_element(f, f + n);
    }
};
