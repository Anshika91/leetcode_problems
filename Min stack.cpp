class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> v;
    MinStack() {
        vector<int> v;
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    void pop() {
        v.erase(v.begin()+v.size()-1);
    }
    
    int top() {
        //return v[v.size()-1];
        return v.back();
    }
    
    int getMin() {
        return *min_element(v.begin(), v.end());
    }
};
