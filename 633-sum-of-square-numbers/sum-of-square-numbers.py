class Solution(object):
    def judgeSquareSum(self, c):
        l=0
        r=int(math.sqrt(c))
        print(r)
        while l<=r:
            one = l*l
            two = r*r
            sum = one+two
            if sum == c:
                return True
            elif sum<c:
                l+=1
            else:
                r-=1
        return False
        