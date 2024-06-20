class Solution(object):
    def canplace(self,position,mid,m):
        prev = position[0]
        cnt = 1
        for i in range(1,len(position)):
            if position[i]-prev>=mid:
                cnt+=1
                prev = position[i]
        return cnt>=m

    def maxDistance(self, position, m):
        position.sort()
        l = 1
        ans = 0
        r=(position[-1]-position[0])/(m-1)
        while l<=r:
            mid = l+(r-l)/2
            if self.canplace(position,mid,m):
                ans = mid
                l = mid+1
            else:
                r=mid-1
        return ans
