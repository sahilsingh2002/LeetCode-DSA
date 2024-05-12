class Solution(object):
    def largestLocal(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(grid)
        ans = []
        for i in range(1,n-1):
            tempr = []
            for j in range(1,n-1):
                temp = 0
                for k in range(i-1,i+2):
                    for m in range(j-1, j+2):
                        temp = max(temp,grid[k][m])
                tempr.append(temp)

            ans.append(tempr)

        return ans


        