class UnionFind{
    vector<int> parent;
    vector<int> rank;
public:
    int cc;

    UnionFind(int n) : parent(n), rank(n){
        ranges::iota(parent, 0);
    }
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool merge(int from, int to){
        int x = find(from), y = find(to);
        if(x == y) return false;
        if(rank[x] > rank[y]) swap(x, y); // union by rank
        parent[x] = y;
        cc--;
        if(rank[x] == rank[y]) rank[y]++;
        return true;
    }
};

// Union-Find, hash table, sorting
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> ump;
        for(int i = 0; i < n; i++){
            int m = accounts[i].size();
            for(int j = 1; j < m; j++){
                const string &s = accounts[i][j];
                if(ump.find(s) == ump.end()){
                    ump[s] = i;
                }
                else{
                    uf.merge(i, ump[s]);
                }
            }
        }
        
        unordered_map<int, vector<string>> umpv;
        for(auto &[s, x] : ump) umpv[uf.find(x)].emplace_back(s);

        vector<vector<string>> res;
        for(auto &[x, v] : umpv){
            sort(v.begin(), v.end());
            vector<string> tmp(1, accounts[x][0]);
            tmp.insert(tmp.end(), v.begin(), v.end());
            res.emplace_back(tmp);
        }
        return res;
    }
    // O(n * m * log(n * m) * L) time, O(n * m * L) extra-space, where n is accounts.length, m is max(accounts[i].length) and L is max(accounts[i][j].length)
};