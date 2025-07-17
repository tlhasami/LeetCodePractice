class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        st,end = 0,len(matrix)*len(matrix[0]) - 1
        while st <= end:
            mid = st + (end - st)//2
            if matrix[mid//len(matrix[0])][mid%len(matrix[0])] == target:
                return True
            elif matrix[mid//len(matrix[0])][mid%len(matrix[0])] < target:
                st = mid + 1
            else:
                end = mid - 1
        return False