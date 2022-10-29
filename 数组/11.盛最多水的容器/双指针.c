int maxArea(int* height, int heightSize){
    int right = heightSize - 1;
    int left = 0;
    int ans = 0;
    while(left < right){
        int ares = fmin(height[left], height[right]) * (right - left);
        ans = fmax(ans, ares);
        if(height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}
