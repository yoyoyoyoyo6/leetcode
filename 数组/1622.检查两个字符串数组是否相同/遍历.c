bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    int p1 = 0, p2 = 0, i = 0, j = 0;
    while(p1 < word1Size && p2 < word2Size){
        while(word1[p1][i] != word2[p2][j]){
            return false;
        }
        i++;
        if(word1[p1][i] == '\0'){
            p1++;
            i = 0;
        }
        j++;
        if(word2[p2][j] == '\0'){
            p2++;
            j = 0;
        }
    }
    //只有当p1 == word1Size && p2 == word2Size 时才能判断出俩字符串完全遍历完才能返回true
    //特殊情况 ： 如两字符串前面的元素都相等，但word1比word2多一个元素，
    //      不能完全相等，p1还未到word1Size时就出来了，但也不完全相等，不能直接返回true
    return p1 == word1Size && p2 == word2Size;
}
