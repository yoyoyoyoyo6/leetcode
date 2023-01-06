class Solution {
public:

    // 维护堆
    void maxHeapify(vector<int> &arr, int i, int len) {
        for(; (i << 1) + 1 <= len;) {
            // 左孩子在数组中的下标
            int l = (i << 1) + 1;
            // 右孩子在数组中的下标
            int r = (i << 1) + 2;
            // 存放当前遍历小树中最大元素的下标
            int largest;

            // 找到当前遍历小树的最大元素的下标
            if(l <= len && arr[l] > arr[i]) {
                largest = l;
            }
            else {
                largest = i;
            }
            if(r <= len && arr[r] > arr[largest]) {
                largest = r;
            }
            // 

            // 如果largest != 当前遍历小树的根结点元素的下标i，
            // 则说明当前遍历小树中最大元素是largest所对应的元素
            // 因为要满足最大堆，所以交换arr[i] and arr[largest]
            if(largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            // else 说明当前小树中最大元素所对应的下标为i
            else {
                break;
            }
        }
    }

    // 建堆
    void buildMaxHeap(vector<int> &arr, int len) {
        // 用自底向上的方法利用maxHeapify把一个大小为arr.length的数组arr转换为最大堆
        // 从len / 2开始遍历的原因是子数组arr([len/2]+1...n)中的元素都是树的叶结点
        // 每一个叶结点都可以看做只包含一个元素的堆
        for(int i = len/2; i>=0; --i) {
            maxHeapify(arr, i, len);
        }
    }

    // 堆排序算法
    void heapSort(vector<int> &arr) {
        int len = (int)arr.size() - 1;
        buildMaxHeap(arr, len);
        for(int i = len; i >= 1; --i) {
            swap(arr[0], arr[i]);
            len -= 1;
            maxHeapify(arr, 0, len);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // 建堆
        // 维护堆
        // 堆排序
        heapSort(nums);
        return nums;
    }
};
