struct ListNode
{
  int val;
  struct ListNode* next;
};

bool isPalindrome(struct ListNode* head)
{
  int arr[100000] = {0};
  int count = 0;
  struct ListNode* node = head;
  while(node != NULL)
  {
    //将链表中的内容存放在数组arr中
    arr[count++] = node->val;
  }
  int i = 0;
  int j = 0;
  for(i = 0, j = count-1; i<j; i++, j--){
    //当i == j时，就break
    //从始至终只要有一个不相等，就要返回false，不是回文链表
    if(arr[i] != arr[j])
    {
      return false;
    }
  }
  //出循环后就一定都满足从两头到中间相等
  return true;
}
