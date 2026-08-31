class UnionFind{
    vector<int> parent;
public:
    int cc;
    UnionFind(int n) : parent(n), cc(n){
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
        if(x < y) swap(x, y);
        parent[x] = y;
        return true;
    }
};

// Union-Find
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        int n = s1.size();
        for(int i = 0; i < n; i++){
            uf.merge(s1[i] - 'a', s2[i] - 'a');
        }
        string ans;
        for(int i = 0; i < baseStr.size(); i++){
            ans.push_back(uf.find(baseStr[i] - 'a') + 'a');
        }
        return ans;
    }
    // O(n * log(|Σ|) + m) = O(n + m) time, O(|Σ|) extra-space, where n is s1.length == s2.length, m is baseStr.length, and |Σ| is the size of the set of alphabet, which is 26.
    // Since |Σ| is at most 26, the operations of the Union-Find(log(|Σ|)) can be considered as O(1).
};