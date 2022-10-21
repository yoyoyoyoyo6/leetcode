struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //创建一个哑节点，存放要return的内容
    struct ListNode* head = NULL;
    //用来操作的节点
    struct ListNode* tail = NULL;
    //carry表示进位
    // if carry/10 > 0 so 要进一位 carry == 1
    int carry = 0;
    //l1 l2 不为空时继续执行
    while (l1 || l2)
    {
        //l1 l2不为空时，就将l1和l2指向的val赋予给n1 and n2
        int n1 = l1 != NULL  ? l1->val : 0;
        int n2 = l2 != NULL ? l2->val : 0;
        //sum存放链表俩值和进位相加的结果
        int sum = n1 + n2 + carry;
        if (!head) 
        {
            //head 为空时，将它指向tail并开辟一块空间
            head = tail = malloc(sizeof(struct ListNode));
            //存放进tail->val 的值只能保存个位
            tail->val = sum % 10;
            tail->next = NULL;
        } 
        else 
        {
            //head不为空时，tail继续向下开辟空间
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        //carry 存放进位 取决于sum是否大于10
        carry = sum / 10;
        if (l1) 
        {
            l1 = l1->next;
        }
        if (l2) 
        {
            l2 = l2->next;
        }
    }
    if (carry > 0) 
    {
        //当l1 或 l2 为NULL 但curry仍然有值时，说明仍然要进位，所以要再开辟一块空间存放carry的值
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    //最后return 哑节点
    return head;
}
