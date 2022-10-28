//第n阶台阶的爬法只能从n-1和n-2来，因为一次只能爬两阶或者一阶

int climbStairs(int n){
    int i = 0;
    int f[46] = {1, 1};
    for(i = 2; i<=n; ++i){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
