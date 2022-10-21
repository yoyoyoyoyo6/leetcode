struct ListNode
{
  int val;
  struct ListNode* next;
};

//思路：先将反转的链表放入n中
//再将n链表的每个val放入int *arr中(要返回的是一个数组，不能直接用int arr)
//最后return arr;
int* reversePrint(struct ListNode* head, int* returnSize){
    struct ListNode* n = NULL;
    int* arr = malloc(10001 * sizeof(int));
    memset(arr, 0, 10000 * sizeof(int));
    struct ListNode* node = head;
    while(node)
    {
        struct ListNode* cur = node->next;
        node->next = n;
        n = node;
        node = cur;
    }
    int i = 0;
    while(n != NULL)
    {
        arr[i++] = n->val;
        n = n->next;
    }
    //这是个传出参数，用于告知调用程序，返回的数组中有效数据的长度。
    //要输出的玩意有多长
    (*returnSize) = i;
    return arr;
}
