/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(void* a, void* b) {
    return *(int*)a - *(int*)b;
}

//主要是用于返回的数组的开辟问题与判断元素是否唯一的问题 and returnSize的运用问题
//双指针 要么都从头开始遍历，后指针遇到某种条件就自增or自减，反正会和前指针产生差值
//    一头一尾遍历时，主要是二分查找或重复元素or排除0，追加等问题

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    *returnSize = 0;
    int index1 = 0, index2 = 0;
    int* intersection = malloc(sizeof(int) * (nums1Size + nums2Size));
    while (index1 < nums1Size && index2 < nums2Size) {
        int num1 = nums1[index1], num2 = nums2[index2];
        if (num1 == num2) {
            // 保证加入元素的唯一性
            //要输出的元素不为空 || 要加入的元素不等于上一个输入的元素
            if (!(*returnSize) || num1 != intersection[(*returnSize) - 1]) {
                intersection[(*returnSize)++] = num1;
            }
            index1++;
            index2++;
        } else if (num1 < num2) {
            index1++;
        } else {
            index2++;
        }
    }
    return intersection;
}
