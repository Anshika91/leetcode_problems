class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //use unordered_map rather than map to speed up
        unordered_map<string, int> counter;
        
        auto comp = [&counter](const string& lhs, const string& rhs){
            return (counter[lhs] == counter[rhs]) ? (lhs > rhs) : 
                (counter[lhs] < counter[rhs]);
        };
        
        priority_queue<string , vector<string>, decltype(comp)> pq(comp);
        vector<string> ans;
        
        for(string& word : words){
            counter[word]++;
        }
        for(auto it = counter.begin(); it != counter.end(); it++){
            pq.push(it->first);
        }
        
        while(k-- > 0){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
