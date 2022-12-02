class Solution {
public:
    int climbStairs(int n) {

        /*
         * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
         * Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Climbing Stairs.
        */
        if (n == 1)
            return 1;

        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }

        return second;
    }
};