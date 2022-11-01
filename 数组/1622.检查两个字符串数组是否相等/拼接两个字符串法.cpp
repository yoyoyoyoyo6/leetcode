#define MAX_STR_LEN 1000

char *join(int **word, int wordSize){
    char *str = (char*)malloc(sizeof(char) * wordSize * MAX_STR_LEN + 1);
    int pos = 0;
    for(int i=0; i<wordSize; i++){
        pos += sprintf(str + pos, "%s", word[i]);
    }
    return str;
}

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    int *str1 = join(word1, word1Size);
    int *str2 = join(word2, word2Size);
    bool ret = strcmp(str1, str2) == 0;
    free(str1);
    free(str2);
    return ret;
}
