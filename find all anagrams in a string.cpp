class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result, hash(26, 0);
        int lenp = p.length(), lens = s.length();
        for(int i = 0; i < lenp; i++) {
            hash[p[i] - 'a']++;
        }
        for(int i = 0; i <= lens - lenp; i++) {
            vector<int> temphash(26, 0);
            for(int j = i; j < i + lenp; j++)
                temphash[s[j] - 'a']++;
            if(temphash == hash)
                result.push_back(i);
        }
        return result;
    }
};
