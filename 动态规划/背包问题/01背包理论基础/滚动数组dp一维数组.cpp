#include<iostream>
#include<vector>
using namespace std;

void test_1_wei_bag_problem(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    //滚动数组：需要满⾜的条件是上⼀层可以重复利⽤，直接拷贝到当前层
    //dp[j]表⽰：容量为j的背包，所背的物品价值可以最⼤为dp[j]

    vector<int> dp(bagWeight + 1, 0);

    for(int i=0; i<weight.size(); i++){     //遍历物品
        //but 为什么二维数组不用逆序遍历
        //because 因为对于⼆维dp，dp[i][j]都是通过上⼀层即dp[i - 1][j]计算⽽来，本层的dp[i][j]并不会被覆盖！
        
        for(int j=bagWeight; j>=weight[0]; j--){    //遍历容量，要逆序遍历，防止物品0重复放入
            //dp[j] 可以由dp[i-1][j-weight[i]] + value[i];
            //直接将上一个元素直接拷贝到下一个元素，可以省去dp[i]的物品编号遍历
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

int main(){
    test_1_wei_bag_problem();
}
