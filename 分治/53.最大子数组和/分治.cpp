class Solution {
public:
    struct Status {
        // lSum 表示 [l,r] 内以 l 为左端点的最大子段和
        // rSum 表示 [l,r] 内以 r 为右端点的最大子段和
        // mSum 表示 [l,r] 内的最大子段和
        // iSum 表示 [l,r] 的区间和
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        // 求数组的一个最大子数组和在分治策略下有三种情况
        // case 1 ：来自左子数组
        // case 2 ：来自右子数组
        // case 3 ：来自中间数组
        int iSum = l.iSum + r.iSum;
        // 求lSum和rSum有两种情况
        // case 1 ：直接是l和r子数组当前的lSum和rSum
        // case 2 ：为包含中间点的子数组的lSum和rSum
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        // mSum则为俩子数组的mSum和包含中间点的子数组（它也可能跨越 m，可能是「左子区间」的 rSum 和 「右子区间」的 lSum 求和）
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int> &a, int l, int r) {
        if(l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m+1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
