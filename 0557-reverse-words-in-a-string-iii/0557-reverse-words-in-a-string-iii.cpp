class Solution {
public:
     string reverseWords(string s) {
        string res="", t="";
        int n = s.size();
        for(int i=0; i<=n; i++) {
            if(i == n){
                reverse(t.begin(), t.end());
                res += t;
            }
            else if(s[i] == ' ' || i==n) {
                reverse(t.begin(), t.end());
                res += t + " ";
                
                t="";
            }
            else {
                t+=s[i];
            }
        }
        return res;
    }
};