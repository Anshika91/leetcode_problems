class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {  // Remove the last bit 1 until n <= m.
            n &= n - 1;
        }
        return n;
    }
};
