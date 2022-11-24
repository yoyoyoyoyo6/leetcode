class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                ret += '%';
                ret += '2';
                ret += '0';
            }
            else {
                ret += s[i];
            }
        }
        return ret;
    }
};
