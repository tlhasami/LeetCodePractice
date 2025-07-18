class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum_count = defaultdict(int)
        prefix_sum_count[0] = 1  # Handle case where subarray starts from index 0

        current_sum = 0
        count = 0

        for num in nums:
            current_sum += num
            count += prefix_sum_count[current_sum - k]
            prefix_sum_count[current_sum] += 1

        return count