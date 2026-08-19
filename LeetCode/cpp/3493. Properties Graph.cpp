class UnionFind{
private:
    vector<int> fa;
    vector<int> sz;
public:
    int cc;
    UnionFind(int n) : fa(n), sz(n, 1), cc(n){
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
        if(sz[x] > sz[y]) swap(x, y); // union by size
        
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
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<unordered_set<int>> sets(n);
        for(int i = 0; i < n; i++){
            sets[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
        }
        UnionFind uf(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cnt = 0;
                for(const int &x : sets[i]){
                    if(sets[j].contains(x)){
                        cnt++;
                    }
                }
                if(cnt >= k){
                    uf.merge(i, j);
                }
            }
        }
        return uf.cc;
    }
    // O(n^2 * m) time, O(n * m) extra-space
};