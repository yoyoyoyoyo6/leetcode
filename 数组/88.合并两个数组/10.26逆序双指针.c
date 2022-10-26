//相对双指针，减少了新建一个数组存放新数组的步骤，减少了内存消耗
//因为nums1数组m后的元素为空，所以可以考虑将大的元素放到nums1的末尾，进而能减少新建数组，也能防止从前遍历导致nums1的元素被覆盖
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p1 = m - 1;
    int p2 = n - 1;
    int tail = m + n - 1;
    int cur;
    while(p1>=0 || p2>=0){
        if(p1 == -1){
            cur = nums2[p2--];
        }
        else if(p2 == -1){
            cur = nums1[p1--];
        }
        //将对比后大的数放到num1后面空的位置
        else if(nums1[p1] > nums2[p2]){
            cur = nums1[p1--];
        }
        else{
            cur = nums2[p2--];
        }
        nums1[tail--] = cur;
    }
}
