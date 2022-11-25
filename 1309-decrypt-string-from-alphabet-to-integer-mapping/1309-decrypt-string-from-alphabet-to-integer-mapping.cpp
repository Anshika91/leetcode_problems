class Solution {
public:
    string freqAlphabets(string s) {

        string res = "";
        for(int i = 0; i < s.size();)
            if(s[i] <= '2' && i + 2 < s.size() && s[i + 2] == '#'){
                res += (s[i] - '0') * 10 + (s[i + 1] - '0') - 1 + 'a';
                i += 3;
            }
            else{
                res += (s[i] - '0') - 1 + 'a';
                i ++;
            }
        return res;
    }
};
