class Solution {
public:
    int characterReplacement(string s, int k) {
        int N = s.size();
        int ans = 0;
   
        for(int i = 0; i < 26; i++){
            int length = 0;
            int used = 0;
            int left = 0, right = 0;
            char c = 'A' + i;
            
            //skip the character not in s
            if(s.find(c) == string::npos)
                continue;
            // cout << c << endl;
            
            while(right < N){
                if(left > 0 && s[left-1] != c){
                    used--;
                }
             
                while(right < N && (s[right] == c || used < k)){
                    if(s[right] != c){
                        used++;
                    }
                    right++;
                  
                }

                length = max(length, right-left);

                left++;
            }            
            ans = max(length, ans);
        }
        
        return ans;
    }
};
