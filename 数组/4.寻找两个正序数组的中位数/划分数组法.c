double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    //保证m <= n
    if (nums1Size > nums2Size) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tempNum = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempNum;
    }
    int m = nums1Size;
    int n = nums2Size;
    //用IMin和IMAX去帮助确定i
    int iMin = 0, iMax = m;
    while(iMin <= iMax){
        int i = (iMin + iMax) / 2;
        //  i + j = 分界后的左边元素的总和 = (m + n + 1) / 2
        //    因为i和j就是将两个数组平均分为两部分了，偶数情况下i + j直接等于(m + n) / 2，
        //      奇数情况下i + j = (m + n + 1) / 2,因为默认规定总元素数为奇数时左界数组的元素要比右界元素多1，但在int下不取小数，所以和偶数情况合并
        int j = (m + n + 1) / 2 - i;
        //如何定义好i的区间
        //在分界时，要遵循两数组(分为上下俩数组，上数组长度为m，下数组长度为n)分界后，nums1[i-1] < nums2[j](左上<右下)     nums2[j-1] < nums1[i](左下<右上)
        //如果nums2[j - 1] > nums1[i](左下>右上)  让i右移，变大(俩数组升序排列)
        if(j != 0 && i != m && nums2[j-1] > nums1[i]){
            iMin = i + 1;
        }
        //如果nums1[i-1] > nums2[j](左上>右下)  让i左移，变小
        else if(i != 0 && j < n && nums1[i-1] > nums2[j]){
            iMax = i - 1;
        }
        else{
            //存放左界数组的max
            int maxLeft = 0;
            //i == 0时，nums1数组的值都较大，所以左界数组的max为nums2[j-1];
            if(i == 0){
                maxLeft = nums2[j-1];
            }
            //如果j == 0，nums2数组的值都较大，所以左界数组的max为nums1[i-1];
            else if(j == 0){
                maxLeft = nums1[i-1];
            }
            //ij都不为0时，直接找nums1[i-1]和nums2[j-1]的最大值即可
            else{
                maxLeft = fmax(nums1[i-1], nums2[j-1]);
            }
            //如果总数组元素为奇数，直接返回左界数组的max即可
            if((m + n) % 2 == 1){
                return maxLeft;
            }
            //如果总数组元素为奇数时
            //存放右界数组的min
            int minRight = 0;
            //i == m时，右界数组的min就为nums2[j];
            if(i == m){
                minRight = nums2[j];
            }
            //j == n时，右界数组的min就为nums1[i];
            else if(j == n){
                minRight = nums1[i];
            }
            //i不等于m且j不等于n时，直接找nums1[i]和nums2[j]的最小值即可
            else{
                minRight = fmin(nums2[j], nums1[i]);
            }
            //为偶数的情况下返回左界数组的max和右界数组的min的和除以2.0(因为题目要返回的是double类型)
            return (maxLeft + minRight) / 2.0;
        }
    }
    //如果都不满足，返回0.0(double类型)
    return 0.0;
}
