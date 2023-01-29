class Solution {
public:
    int countAsterisks(string s) {
        bool valid = true;
        int ans = 0;
        for(int i=0; i<s.size(); ++i) {
            char c = s[i];
            if(c == '|') {
                valid = !valid;
            }
            else if(c == '*' && valid) {
                ++ans;
            }
        }
        return ans;
    }
};
