void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p1 = 0;
    int p2 = 0;
    int cur;
    int sorted[n + m];
    while(p1 < m || p2 < n){
        if(p1 == m){
            cur = nums2[p2++];
        }
        else if(p2 == n){
            cur = nums1[p1++];
        }
        else if(nums1[p1] < nums2[p2]){
            cur = nums1[p1++];
        }
        else{
            cur = nums2[p2++];   
        }
        sorted[p1 + p2 - 1] = cur;
    }
    for(int i=0; i != n+m; ++i){
        nums1[i] = sorted[i];
    }
}
