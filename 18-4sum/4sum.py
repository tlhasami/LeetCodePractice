class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()  # ✅ Missing Step
        ans = []
        for j in range(len(nums)):
            if j > 0 and nums[j] == nums[j - 1]:  # Skip duplicates
                    continue

            for i in range(j+1,len(nums)):
                if i > j + 1 and nums[i] == nums[i - 1]:  # Skip duplicates
                    continue
                    
                left, right = i + 1, len(nums) - 1
                while left < right:
                    total =nums[j] + nums[i] + nums[left] + nums[right]
                    if total < target:
                        left += 1
                    elif total > target:
                        right -= 1
                    else:
                        ans.append([nums[j],nums[i], nums[left], nums[right]])
                        
                        # Skip duplicates
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        
                        left += 1
                        right -= 1
                        
        return ans
