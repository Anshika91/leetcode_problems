class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n != 0) {
            ans = ans + n % 2;
            n = n / 2;
        }
        return ans;
    }
};