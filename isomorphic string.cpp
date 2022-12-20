class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        //need to ensure 1-to-1 mapping,
        //so we need to maps
        map<char, char> m, im;
        set<char> values;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = t[i];
            }else if(m[s[i]] != t[i]){
                return false;
            }
            if(im.find(t[i]) == im.end()){
                im[t[i]] = s[i];
            }else if(im[t[i]] != s[i]){
                return false;
            }
        }
        
        return true;
    }
};
