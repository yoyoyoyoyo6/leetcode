class Solution {
public:

    // quickSort中的划分数组函数partition
    // 使得nums[r]左边的元素要小于等于nums[r],右边的元素要大于nums[r]
    int partition(vector<int> &nums, int l, int r) {
        int x = nums[r];
        int i = l - 1;
        for(int j = l; j <= r - 1; j++) {
            if(nums[j] <= x) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i + 1;
    }

    // 随机化快速排序的划分数组
    int randomized_partition(vector<int> &arr, int l, int r) {
        int x = rand() % (r - l + 1) + l;
        swap(arr[x], arr[r]);
        return partition(arr, l, r);
    }

    // 期望为线性时间的选择算法
    // 有一点随机化快速排序+二分的味道
    void randomized_select(vector<int> &nums, int l, int r, int k) {
        // 递归停止条件
        if(l >= r) return;

        // 划分数组，形成nums[mid]前的元素要小于nums[mid]，nums[mid]后的元素要大于nums[mid]
        int mid = partition(nums, l, r);
        // q记录mid前有多少个元素，包括mid
        int q = mid - l + 1;

        // 此时q就为要找的第k小的元素
        if(k == q) {
            return;
        }
        // 当k < q时，则要找的k在mid的前面，所以对l到mid-1的区间进行递归
        else if(k < q) {
            randomized_select(nums, l, mid - 1, k);
        }
        // 反之对mid+1到r的区间进行递归
        else {
            randomized_select(nums, mid + 1, r, k - q);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 调用randomized_select后，nums[k]前的元素就都满足要求
        randomized_select(arr, 0, arr.size() - 1, k);
        vector<int> vec(k, 0);
        for(int i=0; i<k; i++) {
            vec[i] = arr[i];
        }
        return vec;
    }
};
