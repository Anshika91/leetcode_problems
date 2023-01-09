class DSU{
public:
    vector<int> parent;
    
    DSU(int N){
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(parent[x] != x){ //initial state
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y){
        // not "parent[x] = find(parent[y]);"
        // not "parent[y] = find(parent[x]);"
        // combine two component's head together
        parent[find(x)] = find(y);
    }
};
