class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || k % n == 0) return;
        k %= n;
        int count = 0; // number of elements in correct position
        int start = 0;
        while(count < n){
            int i = start;
            int prev = nums[i]; // value of number in previous index
            do{
                i = (i + k) % n; // destination index
                swap(prev, nums[i]);
                ++count;
            }while(i != start);
            ++start;
        }
    }
};