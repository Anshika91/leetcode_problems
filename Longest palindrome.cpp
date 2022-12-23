class Solution {
public:
    int longestPalindrome(string s) {
        int hash[256] = {0}, len = 0, flag = 0;
        for(int i = 0; i < s.length(); i++)
            hash[s[i]]++;
        for(int i = 0; i < 256; i++) {
            if(hash[i] % 2 == 0) {
                len += hash[i];
            } else {
                len += (hash[i] - 1);
                flag = 1;
            }
        }
        return len + flag;
    }
};
