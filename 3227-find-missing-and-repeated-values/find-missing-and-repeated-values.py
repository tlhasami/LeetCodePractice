class Solution(object):
    def findMissingAndRepeatedValues(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        check = [0] * (len(grid) * len(grid))
        for arr in grid:
            for val in arr:
                check[val-1] += 1
        print(check)
        ans = [0,0]
        for i,val in enumerate(check):
            if val == 2:
                ans[0] = i+1
            if val == 0:
                ans[1] = i+1
        
        return ans
