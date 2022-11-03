int* countBits(int n, int* returnSize){
    //开辟一块空间，大小为n+1
    int *ans = malloc(sizeof(int) * (n+1));
    *returnSize = n + 1;
    //设定初始状态
    ans[0] = 0;
    for(int i=1; i<=n; i++){
        //写出状态转移方程 + 设计状态
        //状态分为两种，当i为奇数时，相对前面的偶数的比特位只多了最后一位的一，所以可以直接写为ans[i] = ans[i-1] + 1;
        //        当i为偶数时，i的比特位也就等于i/2后的比特位，因为i/2时，相当于把二进制位的最后的0给舍掉，所以可以直接写为ans[i] = ans[i/2];
        if(i % 2 == 1){
            ans[i] = ans[i-1] + 1;
        }
        else{
            ans[i] = ans[i/2];
        }
    }
    return ans;
}
