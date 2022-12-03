class Solution {
public:
    int secondHighest(string s) {
        // first、second 分别记录 s 中第一大的数字与第二大的数字
        int first = -1, second = -1;
        for(auto ch : s) {
            if(isdigit(ch)) {
                int sum = ch - '0';
                // 如果sum大于first，则说明sum为第一大的数，first为第二大的数，所以将second更新为first
                // first更新为sum
                if(sum > first) {
                    second = first;
                    first = sum;
                }
                // 如果满足second < sum < first，那么就说明sum为第二大的数，将second更新为sum即可
                else if(sum < first && sum > second) {
                    second = sum;
                }
            }
        }
        return second;
    }
};
