class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None. Modifies nums in-place.
        """
        # find smallest in order
        i = len(nums)-2
        while i >= 0 and nums[i+1] <= nums[i]:
            i-=1
        # find the first larger number then nums[i]
        if i >= 0:
            j = len(nums)-1
            while nums[i] >= nums[j]:
                j-=1
            nums[i],nums[j] = nums[j],nums[i]

        nums[i+1:] = nums[i+1:][::-1]  # Reverse from index 2 to end
            