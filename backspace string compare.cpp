class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s, t;
        
        for(char ch : S)
        {
            if(ch == '#'){
                if(s.size()) s.pop();
            }
            else s.push(ch);
        }
        
        for(char ch : T)
        {
            if(ch == '#'){
                if(t.size()) t.pop();
            }
            
            else t.push(ch);
        }
        
        while(s.size() && t.size())
        {
            if(s.top() != t.top()) return false;
            s.pop(), t.pop();
        }
        
        if(s.size() || t.size()) return false;
        return true;
    }
};
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
