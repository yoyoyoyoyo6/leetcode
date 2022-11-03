int bin(int x){
    int count = 0;
    while(x > 0){
        x &= (x - 1);
        count++;
    }
    return count;
}

int* countBits(int n, int* returnSize){
    int *ans = malloc(sizeof(int) * (n+1));
    *returnSize = n + 1;
    for(int i=0; i<=n; i++){
        ans[i] = bin(i);
    }
    return ans;
}
