class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        import re
        exp = re.match(p, s)
        if not exp:
            return False
        if exp.start() == 0 and exp.end() == len(s):
            return True
        return False
        
        