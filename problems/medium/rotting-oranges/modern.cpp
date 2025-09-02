#include <vector>
#include <deque>

using namespace std;

// BFS с std::deque
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.size();
        deque<pair<int, int>> dq;
        int fresh = 0, time = 0;
        vector<pair<int, int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j) {
                if (grid[i][j]==2) dq.push_back({i,j});
                else if (grid[i][j]==1) fresh++;
            }
        while (!dq.empty() && fresh) {
            int sz = dq.size();
            while (sz--) {
                auto [x,y]=dq.front(); dq.pop_front();
                for (auto [dx,dy]:dirs) {
                    int nx=x+dx, ny=y+dy;
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==1){
                        grid[nx][ny]=2; fresh--;
                        dq.push_back({nx,ny});
                    }
                }
            }
            ++time;
        }
        return fresh? -1: time;
    }
};
// Время: O(m·n)  Память: O(m·n)
