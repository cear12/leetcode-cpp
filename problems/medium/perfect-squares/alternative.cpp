#include <queue>

using namespace std;

class Solution2 {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> visited(n+1, false);
        q.push(n); visited[n] = true;
        int level = 0;
        while (!q.empty()) {
            int sz = q.size(); level++;
            for (int i = 0; i < sz; ++i) {
                int num = q.front(); q.pop();
                for (int j = 1; j * j <= num; ++j) {
                    int next = num - j*j;
                    if (next == 0) return level;
                    if (!visited[next]) {
                        q.push(next); visited[next] = true;
                    }
                }
            }
        }
        return 0;
    }
};
