class Solution(object):
    def appendCharacters(self, s, t):
        idx = 0
        for i in s:
            if(idx>=len(t)):
                break
            if i==t[idx]:
                idx+=1
        return len(t)-idx
        