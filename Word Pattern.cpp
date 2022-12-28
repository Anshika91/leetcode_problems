class Solution {
public:
    bool wordPattern(string pattern, string str) {  
        map<char, int> p2i;
        map<string, int> s2i;
        int i = 0, n = pattern.size();
        
        istringstream is(str);
        for(string word; is >> word; i++){
            if(i == n || p2i[pattern[i]] != s2i[word]){
                return false;
            }
            //can't set the value to 0, because 0 is the default value
            p2i[pattern[i]] = s2i[word] = i+1;
        }
        
        //i means token count now
        return i == n;
    }
};
