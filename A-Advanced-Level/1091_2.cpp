/** bfs **/
#include <bits/stdc++.h>
using namespace std;

int m, n, l, t;

bool g[60][1286][128];
bool visited[60][1286][128];
int dir[6][3] = {{0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0}};

struct node {
    int x, y, z;
};

inline bool check(node e) {
    if (e.x<0 || e.y<0 || e.z<0) return false;
    if (e.x>=m || e.y>=n || e.z>=l) return false;
    if (visited[e.z][e.x][e.y] || !g[e.z][e.x][e.y]) return false;
    return true;
}

int bfs(int x, int y, int z) {
    int res = 0;
    queue<node> q;
    node e;
    e.x = x;
    e.y = y;
    e.z = z;
    q.push(e);
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        res++;
        visited[tmp.z][tmp.x][tmp.y] = true;
        for (int i=0; i<6; i++) {
            node near;
            near.x = tmp.x + dir[i][1];
            near.y = tmp.y + dir[i][2];
            near.z = tmp.z + dir[i][0];
            if (check(near)) {
                q.push(near);
                visited[near.z][near.x][near.y] = true;
            }
        }
    }
    return (res >= t ? res : 0);
}

int main() {
    memset(visited, 0, sizeof(visited));
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int k=0; k<l; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d", &g[k][i][j]);
            }
        }
    }
    int ans = 0;
    for (int k=0; k<l; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (g[k][i][j] && !visited[k][i][j]) {
                    ans += bfs(i, j, k);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
