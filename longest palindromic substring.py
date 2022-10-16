class Solution:
    def longestPalindrome(self, s: str) -> str:
        N = len(s)
        def LP(l,r):
            while r < N and l >=0:
                if s[r] != s[l]:
                    break
                    r+=1
                    l-=1
            return l+1,r
        start,end = 0,0
        for i in range(N):
            l,r = LP(i,i)
            if(r-l) > (end-start):
                end = r
                start = l
            l,r = LP(i,i+1)    
            if(r-l) > (end-start):
                end = r
                start = l
        return s[start:end]        
