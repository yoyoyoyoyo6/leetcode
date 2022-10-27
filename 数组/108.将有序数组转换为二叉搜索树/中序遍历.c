struct TreeNode{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

struct TreeNode* helper(int* nums, int left, int right){
  if(left > right){
    return NULL;
  }
  //从数组中间靠左为根节点
  int mid = (left + right) / 2;
  struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  root->val = nums[mid];
  //小的放左
  root->left = helper(nums, left, mid-1);
  //大的放右
  root->right = helper(nums, mid+1, right);
  return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
  return helper(nums, 0, numsSize-1);
}
