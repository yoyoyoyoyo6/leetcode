class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        // 排除0的情况
        if(k == 0) {
            return vec;
        }
        // 优先队列，插入进去自动排序
        priority_queue<int> Q;
        // 插入k个
        for(int i=0; i<k; i++) {
            Q.push(arr[i]);
        }
        // 与后k到arr.size()-1和前面插入Q中的k个元素进行对比
        for(int i = k; i<arr.size(); i++) {
            // 将小的插入优先队列中
            if(Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        // 退出上一个for循环时，优先队列中一共k个元素，都是小于数组中第k+1个元素的
        // 所以直接取出放入vec中即可
        for(int i=0; i<k; i++) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};
