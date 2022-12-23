class MyHashMap {
public:
    vector<int> keys;
    vector<int> values;
    
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if(it!=keys.end()){
            values[(it - keys.begin())] = value;
        }else{
            keys.push_back(key);
            values.push_back(value);
        }
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if(it==keys.end()){
            return -1;
        }else{
            return values[it-keys.begin()];
        }
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if(it!=keys.end()){
            keys.erase(it);
            values.erase(values.begin() + (it - keys.begin()));
        }
    }
};
