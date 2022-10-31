int lengthOfLongestSubstring(char * s){
    //滑动窗口

    int indexLeft   = 0;
    int indexRight  = 0;
    //int len = strlen(s);

    //哈希思想为值和位置之间的关系
    int hashMap[255] = { 0 };
    int maxCount = 0;
    while (indexRight < strlen(s))
    {
        //从前向后遍历，只要出现过的元素都会被加上indexRight，如果遍历到后面时不为0，则说明前面出现过了，
        //      因为是拿字符串元素作为键的
        if (hashMap[s[indexRight]] != 0)
        {
            //重复出现了,之前遍历过了该元素且重复出现才不为0
            if(hashMap[s[indexRight]] > indexLeft)
                //缩小间距
                indexLeft = hashMap[s[indexRight]];
            //让该元素的哈希值再增加，做标记
            hashMap[s[indexRight]] = indexRight + 1;
        }
        //如果为0，则让它增加一个indexRight做标记，继续向后遍历
        else
        {
            hashMap[s[indexRight]] = indexRight + 1;
        }
        //找出最大间隔
        maxCount = fmax(maxCount, indexRight - indexLeft + 1);
        indexRight++;
    }
    return maxCount;
}
