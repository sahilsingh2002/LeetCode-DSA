class Solution:
    def flipr(self,grid: List[List[int]],i):
        for j in range(len(grid[0])):
            grid[i][j] = 0 if grid[i][j] == 1 else 1
    def flipc(self,grid: List[List[int]],j):
        for i in range(len(grid)):
            grid[i][j] = 0 if grid[i][j] == 1 else 1
    def matrixScore(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            if grid[i][0]==0:
                self.flipr(grid,i)
        
        for j in range(1,n):
            zeroes = 0
            ones = 0
            for i in range(m):
                if(grid[i][j]==0):
                    zeroes+=1
                
                else:
                    ones+=1
            
            if(zeroes>ones):
                self.flipc(grid,j)
        ans = 0
        for i in range(m):
            for j in range(n-1,-1,-1):
                if grid[i][j]==1:
                    ans+=pow(2,n-1-j)

        return ans
