// 直接排序，取前k-1位
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> vec(k, 0);
        for(int i = 0; i<k; i++) {
            vec[i] = arr[i];
        }
        return vec;
    }
};
