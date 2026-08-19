class UnionFind{
    vector<int> fa;
    vector<int> sz;
public:
    int cc;
    UnionFind(int n) : fa(n), sz(n, 1), cc(n){
        ranges::iota(fa, 0);
    }

    int find(int x){
        if(fa[x] != x){
            fa[x] = find(fa[x]); // path compression
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
};

// Union-Find
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();

        UnionFind uf(26);
        for(const string &s : equations){
            int x = s[0] - 'a', y = s[3] - 'a';
            if(s[1] == '='){
                if(!uf.is_same(x, y)){
                    uf.merge(x, y);
                }
            }
        }

        for(const string &s : equations){
            int x = s[0] - 'a', y = s[3] - 'a';
            if(s[1] == '!'){
                if(uf.is_same(x, y)){
                    return false;
                }
            }
        }

        return true;
    }
    // O(n + C * α(n)) time, O(C), where C <= 26
};