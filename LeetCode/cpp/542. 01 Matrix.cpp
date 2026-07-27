class Solution {
public:
    bool is_valid(int x, int y, int m, int n){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) q.push({i, j}); // 將0當作BFS起點
                else mat[i][j] = INT_MAX;
            }
        }
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        const int d_cnt = 4;
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y = p.second;
            for(int i = 0; i < d_cnt; i++){
                int now_x = x + dx[i], now_y = y + dy[i];
                if(is_valid(now_x, now_y, m, n) && mat[now_x][now_y] > mat[x][y] + 1){ // 如果mat[now_x][now_y] <= mat[x][y] + 1代表mat[now_x][now_y]找到更小的值, 沒必要更新
                    mat[now_x][now_y] = mat[x][y] + 1;
                    q.push({now_x, now_y});
                }
            }
        }
        return mat;
    }
};