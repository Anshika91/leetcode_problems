class Solution {
public:
    int search(vector<int> nums, int target)
{
	int n = nums.size();

	for (int i = 0; i < n; i++)
	{
		int currElement = nums[i];
		if (currElement == target)
		{
			return i;
		}
	}

	return -1;   // if target is not present 
}
};