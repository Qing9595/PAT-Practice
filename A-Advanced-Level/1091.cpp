/** dfs **/
/** stack overflow !!! **/
#include <bits/stdc++.h>
using namespace std;

int m, n, l, t;

int g[60][1286][128];
bool visited[60][1286][128];
int dir[6][3] = {{0,-1,0},{0,1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0}};

bool check(int x, int y, int z) {
    if (x<0 || y<0 || z<0) return false;
    if (x>=m || y>=n || z>=l) return false;
    if (visited[z][x][y] || !g[z][x][y]) return false;
    return true;
}

int sizek = 0;

void dfs(int x, int y, int z) {
    if (check(x, y, z)) {
        sizek++;
        visited[z][x][y] = true;
        for (int loop=0; loop<6; loop++) {
            dfs(x+dir[loop][1], y+dir[loop][2], z+dir[loop][0]);
        }
    }
    return;
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
                    sizek = 0;
                    dfs(i, j, k);
                    if (sizek >= t) {ans += sizek;}
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
