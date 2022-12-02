class Solution {
public:
    vector<int> minOperations(string boxes) {
        // if(boxes[i] == '1') box中有小球
        // if(boxex[i] == '0') box中无小球

        // 将一个小球放到相邻的盒子之中
        // 第i个盒子和第j个盒子相邻需满足abs(i - j) == 1

        // return一个长度为n的数组answer，其中answer[i]是将小球移动到第i个盒子所需的最小操作数

        int n = boxes.size();
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {

            int sm = 0;
            for(int j=0; j<n; j++) {
                
                if(boxes[j] == '1') {
                    // 求得第i个箱子的球挪到第j个箱子的所需的最小操作数，要累加
                    // 累加的目的是模拟从第i个箱子如何一步步来到第j个箱子
                    sm += abs(j - i);
                }
            }

            ans[i] = sm;
        }
        return ans;
    }
};
