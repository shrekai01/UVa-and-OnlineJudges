class UnionFind{
private:
    vector<int> fa;
    vector<int> sz;
public:
    int cc;
    UnionFind(int n): fa(n), sz(n, 1), cc(n){
        ranges::iota(fa, 0);
    }
    
    int find(int x){
        if(fa[x] != x){
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    
    bool is_same(int x, int y){
        return find(x) == find(y);
    }

    bool merge(int from, int to){
        int x = find(from), y = find(to);
        if(x == y) return false;

        fa[x] = y;
        sz[y] += sz[x];
        cc--;
        return true;
    }
    
    int get_size(int x){
        return sz[find(x)];
    }
};

// Union-Find

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for(const auto &edge : edges){
            int x = edge[0] - 1, y = edge[1] - 1;
            if(uf.find(x) != uf.find(y)){
                uf.merge(x, y);
            }
            else{
                return edge;
            }
        }
        return vector<int>();
    }
    // O(n * log(n)) time, O(n) extra-space
    // path compression without union by rank or union by size
};