class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        for (char c : s) {
            if (isalnum(c)) {
                res += tolower(c);
            }
        }
        string rev = res;
        reverse(rev.begin(),rev.end());
        return rev == res;
    }
};
