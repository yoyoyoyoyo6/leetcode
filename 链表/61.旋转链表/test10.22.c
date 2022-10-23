struct ListNode
{
  int val;
  struct ListNode* next;
};

//步骤
//创建一个哑节点newNOde指向head，一个指向哑节点的节点ited
//计算出链表的长度n，并且让ited指向链表最后一个节点
//让链表最后一个节点指向头，形成环形链表
//如果k大于等于n，则要移动的位数就等于向右移动 k % n位，如果k<n，则移动n-k位即可
//综上所述，创建一个变量add，让它代表要移动的位数 = n - k % n;
//如果add == n 说明不用移动
//再将ited指向向右移动了add位处
struct ListNode* rotateRight(struct ListNode* head, int k){
    // k == 0不用旋转， head为空和只有一个元素不用旋转
    if(k == 0 || head == NULL || head->next == NULL)
    {
        return head;
    }
    //n存放链表长度
    int n = 1;
    //ited作为操作的节点
    struct ListNode* ited = head;
    //将ited指向链表head的最后一个节点
    //将n存放计算出的链表长度
    while(ited->next != NULL)
    {
        ited = ited->next;
        n++;
    }
    //创建一个add存放要移动的位数
    int add = n - k % n;
    //如果add为0，则不用移动
    if(add == n)
    {
        return head;
    }
    //让位指向头，形成环形链表
    ited->next = head;
    //将ited移动add位
    while(add--)
    {
        ited = ited->next;
    }
    struct ListNode* ans = ited->next;
    ited->next = NULL;
    return ans;
}
