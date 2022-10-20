class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return(False)
        rev_num = 0
        digit = 0
        while(x // (10**digit)!=0):
            rev_num = (rev_num * 10) +(x // (10**digit) % 10)
            digit += 1
        return(x == rev_num)    
        