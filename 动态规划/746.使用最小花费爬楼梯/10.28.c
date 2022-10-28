//设计状态：爬到第i层，可以从第i-1或i-2层爬到，那么花费就要考虑i-1和i-2花费的min 
//状态转移函数：f[i]= min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
//设定初始状态：f[0] = f[1] = 0;

int min(int a, int b){
    return a < b ? a: b;
}

int minCostClimbingStairs(int* cost, int costSize){
    int i;
    int f[1001] = {0, 0};
    for(i = 2; i<=costSize; ++i){
        f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
    }
    return f[costSize];
}
