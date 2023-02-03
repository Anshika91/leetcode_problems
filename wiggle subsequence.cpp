#include <vector>

using namespace std;

class Solution {
public:

  int wiggleMaxLength(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> dp(nums.size());

    dp[0] = 1;
    int sign_last;

    for (size_t i = 1, j = 0; i < nums.size(); i++) {

      dp[i] = dp[j];

      int delta = nums[i] - nums[j];
      int sign = sgn(delta);

      if (0 == sign) {
        continue;
      }

      if (0 == j || sign == -sign_last) {
        dp[i]++;
        sign_last = sign;
      }

      j = i;
    }

    return dp[nums.size() - 1];
  }

protected:
  int sgn(int x) {
    if (x > 0)
      return +1;
    if (x < 0)
      return -1;
    return 0;
  }
};
