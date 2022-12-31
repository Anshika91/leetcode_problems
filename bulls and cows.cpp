class Solution {
public:
    string getHint(string secret, string guess) {
        int N = secret.size();
        int A = 0, B = 0;

        for(int i = N-1; i >= 0; i--){
            if(secret[i] == guess[i]){
                A++;
                secret.erase(i,1);
                guess.erase(i,1);
            }
        }

        //use set: WA
        set<char> s1(secret.begin(), secret.end()), s2(guess.begin(), guess.end());
        vector<char> tmp(4);
        B = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), tmp.begin()) - tmp.begin();
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
