class Solution {
public:
    // DFS
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size(), n = image[0].size();
        
        auto dfs = [&](this auto &&dfs, int i, int j, const int orig) -> void{
            if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != orig) return;
            image[i][j] = color;
            for(auto &[dx, dy] : dirs){
                dfs(i + dx, j + dy, orig);
            }
        };

        dfs(sr, sc, image[sr][sc]);
        return image;
    }
    // O(m * n) time, O(m * n) extra-space
};