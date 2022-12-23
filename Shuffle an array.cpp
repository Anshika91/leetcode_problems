
class Solution {
private:
    vector<int> nums;
    vector<int> origin;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        this->origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--) {
            int index = rand() % (i + 1);
            swap(nums[i], nums[index]);
        }
        return nums;
    }
};
