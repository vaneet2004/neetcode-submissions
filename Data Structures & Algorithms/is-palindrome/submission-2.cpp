class Solution {
public:
    bool isAlphaNum(char c){
        if(c>='0'&&c<='9'||(tolower(c)>='a'&& tolower(c)<='z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left <= right) {

            if (!isAlphaNum(s[left])) {
                left++;
                continue;
            }

            if (!isAlphaNum(s[right])) {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};