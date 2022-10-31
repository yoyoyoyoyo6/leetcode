int lengthOfLongestSubstring(char * s){
    int left = 0;
    int right = 0;
    int max = 0;
    int i, j;
    int len = strlen(s);
    //是否有相同字符,作为判断，不做计数
    int haveSameChar = 0;
    for(i = 0; i<len; i++){
        if(left <= right){
            haveSameChar = 0;
            for(j=left; j<right; j++){
                //如果有相同字符，将haveSameChar改为真，然后跳出循环
                if(s[right] == s[j]){
                    haveSameChar = 1;
                    break;
                }
            }
            //haveSameChar为真，让左指针继续向前遍历，缩小间距
            if(haveSameChar){
                left = j + 1;
            }
        }
        //找出最大间距即为结果
        max = max < (right - left + 1) ? (right - left + 1): max;
        //右移，向前遍历
        right++;
    }
    return max;
}
