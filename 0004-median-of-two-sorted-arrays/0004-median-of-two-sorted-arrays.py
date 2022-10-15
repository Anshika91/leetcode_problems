class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # arr1 = [1,2,3]
        # arr2 = [5,6,7]
        # arr = [1,2,3,4,5,6,7]
        nums = nums1 + nums2
        nums = sorted(nums)
        mid = len(nums) // 2
        if len(nums) % 2 !=0:
            return nums[mid]
        else:
            mid = nums[mid-1] + nums[mid]
            return mid / 2.0
        
        
        