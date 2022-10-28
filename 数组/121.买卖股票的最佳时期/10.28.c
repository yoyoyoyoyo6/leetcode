//拿到数组的min，要返回的是数组的max-min的值，但是min又要在max前面
//直接拿prices[i]去判断，min拿到后，比它大的prices[i]去减它，得到的值如果比max大，说明max仍不是要返回的最大差值,继续将max赋值

int maxProfit(int* prices, int pricesSize){
    int max = 0, min = prices[0];
    for(int i=0; i<pricesSize; i++){
        if(prices[i] < min){
            min = prices[i];
        }
        else if(prices[i] - min> max){
            max = prices[i] - min;
        }
    }
    return max;
}
