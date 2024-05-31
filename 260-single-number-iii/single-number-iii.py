class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = 0
        for i in nums:
            xor = xor^i
        mask = xor&(-1*xor)
        first = 0
        for i in nums:
            if((mask&i)==mask):
                first = first^i
        second = first^xor
        return [first,second]
