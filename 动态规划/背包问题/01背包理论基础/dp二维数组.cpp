#include<iostream>
using namespace std;

void test_2_wei_bag_problem1(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    //背包的max容量
    int bagwegiht = 4;

    //dp数组:dp[i][j]表示从下标为[0-i]的物品中选取一个，放入容量为j的背包中，价值总和最大为多少
    //所以i的大小为weight.size() + 1,要从0开始遍历。j的大小就为bagwegiht + 1。并且二维数组中的每个元素都初始化为0
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bagweight + 1, 0));
    
    //初始化状态
    //dp[i][0] 因为容量为0，所以价值也为0,创建二维数组时已经将数组中的元素都初始化为0，所以不用操作
    //dp[0][j] 是标号为0的物品的价值，所以都赋值为value[0],并且每次遍历j都要剪去weight[0]的重量
    for(int j = bagwegiht; j >= weight[0]; j--){
        dp[0][j] = dp[0][j - weight[0]] + value[0];
    }

    //遍历每个物品
    for(int i=1; i<weight.size(); i++){
        //遍历背包容量
        for(int j=0; j<=bagwegiht; j++){

            //如果当前容量要比要放进来的物品的重量要小，则直接跳过该元素
            if(j < weight[i]) dp[i][j] = dp[i-1][j];

            //状态分为两种，拿or不拿
            //拿：则容量要减去weight[i](当前遍历的物品的重量)+value[i](当前物品的价值)
            //不拿：直接下一个物品即可
            //所以得到dp[i][j]就上述两种情况的max
            //得到状态方程 dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    }
    //输出dp数组最后一个元素
    cout << dp[weight.size()][bagwegiht] << endl;
}
  
  int main(){
    test_2_wei_bag_problem1();
}
