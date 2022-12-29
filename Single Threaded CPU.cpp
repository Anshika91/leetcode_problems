class Solution {
private:
    template<typename T>
    void print(T q) { 
        while(!q.empty()) {
            auto t = q.top();
            cout << t[2]<< "[" << t[0] <<","<< t[1] << "] ";
            q.pop();
        }
        std::cout << '\n';
    }
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // push the index into each task.
        // [enQueueTime, ProcessingTime, index]
        for(int i=0; i<tasks.size(); i++){
            tasks[i].push_back(i); 
        }
        
        //Sort the tasks by enQueueTtime
        sort(tasks.begin(), tasks.end(), [&](vector<int>& lhs, vector<int>& rhs) {
            return lhs[0] < rhs[0];
        });
        
        //Sort function for tasks priority queue.
        auto comp = [&](vector<int>& lhs, vector<int>& rhs){
            // if the processing time is same ,get the smaller index
            if (lhs[1] == rhs[1]) return lhs[2] > rhs[2]; 
            // choosing the shorter processing time.
            return lhs[1] > rhs[1];
        };

        priority_queue<vector<int>, std::vector<vector<int>>, decltype(comp)> q (comp);
        vector<int> result;
        
        int i = 0;
        while (i < tasks.size()) {
            long time = tasks[i][0];
            int start = i;
            for (;i < tasks.size() && tasks[start][0] == tasks[i][0];i++ ) {
                q.push(tasks[i]);
            }
            //print(q);
           
            while(!q.empty()){
                //processing the task
                auto t = q.top(); q.pop();
              
                result.push_back(t[2]);
                
              
                time += t[1];
                for(;i < tasks.size() && tasks[i][0] <= time; i++) {
                    q.push(tasks[i]);
                }
               
            }
        }
        return result;
    }
};
