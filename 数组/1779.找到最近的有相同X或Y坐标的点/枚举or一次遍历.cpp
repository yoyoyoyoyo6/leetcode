class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        // ans作为return的值，
        // mi作为取到有效点的曼哈顿距离的最小下标的工具
        int ans = -1, mi = 1e6;
        for(int i=0; i<points.size(); i++) {
            // px和px作为取得当前点的xy坐标的工具
            int px = points[i][0], py = points[i][1];
            // 如果当前遍历点为有效点
            if(px == x || py == y) {
                // p存放当前有效点的曼哈顿距离
                int p = abs(x - px) + abs(y - py);
                // 为取到有效点下标最小的一个
                // 如果当前取得的曼哈顿距离要比上一次取得的最小曼哈顿距离要小
                if(p < mi) {
                    // 将mi继续更新为当前最小的曼哈顿距离
                    mi = p;
                    // 让ans存放当前最小曼哈顿距离的下标，作为return的值
                    ans = i;
                }
            }
        }
        return ans;
    }
};
