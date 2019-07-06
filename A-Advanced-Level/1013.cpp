#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

static bool g[MAXN][MAXN];
static bool vis[MAXN];
static int n, m, k;
static int del;

void dfs(const int &s) {
    vis[s] = true;
    for (int i=1; i<=n; i++) {
        if (!vis[i] && i != del && g[s][i]) {
            dfs(i);
        }
    }
    return;
}

int main() {
    memset(g, 0, sizeof(g));
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = true;
        g[y][x] = true;
    }
    while (k--) {
        int ans = 0;
        scanf("%d", &del);
        memset(vis, 0, sizeof(vis));
        for (int i=1; i<=n; i++) {
            if (!vis[i] && i != del) {
                dfs(i);
                ans++;
            }
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
