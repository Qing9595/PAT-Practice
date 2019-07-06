/** dfs **/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 500
#define INF INT_MAX

static int n, m, s, d;
static int dis[MAXN][MAXN], cost[MAXN][MAXN];

static int shortest = INF, mincost = INF;
static bool vis[MAXN];
static vector<int> tmppath, path;

void dfs(const int &cur_point, const int &cur_dist, const int &cur_cost) {
    if (cur_dist > shortest) {
        return;
    }
    if (cur_point == d) {
        shortest = cur_dist;
        if (cur_cost < mincost) {
            mincost = cur_cost;
            path = tmppath;
        }
        return;
    }
    for (int i=0; i<n; i++) {
        if (!vis[i] && dis[cur_point][i] < INF) {
            vis[i] = true;
            tmppath.push_back(i);
            dfs(i, cur_dist + dis[cur_point][i], cur_cost + cost[cur_point][i]);
            tmppath.pop_back();
            vis[i] = false;
        }
    }
    return;
}

void dfs() {
    vis[s] = true;
    dfs(s, 0, 0);
    return;
}

inline void init() {
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAXN; j++) {
            if (i != j) {
                dis[i][j] = INF;
                cost[i][j] = INF;
            }
            else {
                dis[i][j] = 0;
                cost[i][j] = 0;
            }
        }
    }
    return;
}

int main() {
    init();
    memset(vis, 0, sizeof(vis));
    scanf("%d%d%d%d", &n, &m, &s, &d);
    while (m--) {
        int x, y, d, c;
        scanf("%d%d%d%d", &x, &y, &d, &c);
        dis[x][y] = d;
        dis[y][x] = d;
        cost[x][y] = c;
        cost[y][x] = c;
    }
    dfs();
    printf("%d ", s);
    for (int i=0; i<path.size(); i++) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", shortest, mincost);
    return 0;
}
