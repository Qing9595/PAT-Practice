#include <bits/stdc++.h>
using namespace std;
#define MAXN 501
#define INF INT_MAX

static int cmax, n, sp, m;
static int g[MAXN][MAXN], store[MAXN];
static int shortest = INF;

static vector<int> tmppath;
static vector<int> path;
static bool vis[MAXN];
static int minneed = INF, minremain = INF;

void dfs(const int cur_point, const int cur_dist) {
    if (cur_dist > shortest) {
        return;
    }
    if (cur_point == sp) {
        int need = 0, remain = 0;
        for (int i=0; i<tmppath.size(); i++) {
            if (store[tmppath[i]] > cmax) {
                remain += (store[tmppath[i]] - cmax);
            }
            else {
                if (remain > cmax - store[tmppath[i]]) {
                    remain -= (cmax - store[tmppath[i]]);
                }
                else {
                    need += (cmax - store[tmppath[i]] - remain);
                    remain = 0;
                }
            }
        }
        if (need < minneed) {
            path = tmppath;
            minneed = need;
            minremain = remain;
            return;
        }
        if (need == minneed && remain < minremain) {
            path = tmppath;
            minneed = need;
            minremain = remain;
            return;
        }
    }
    for (int i=0; i<=n; i++) {
        if (!vis[i] && g[cur_point][i] < INF) {
            vis[i] = true;
            tmppath.push_back(i);
            dfs(i, cur_dist + g[cur_point][i]);
            tmppath.pop_back();
            vis[i] = false;
        }
    }
    return;
}

void dfs() {
    vis[0] = true;
    dfs(0, 0);
    return;
}

void dijk(const int &src, const int &dest) {
    int dist[n + 1];
    bool sloved[n + 1];
    memset(vis, 0, sizeof(sloved));
    for (int i=0; i<=n; i++) {
        dist[i] = g[src][i];
    }
    sloved[src] = true;
    for (int i=0; i<n; i++) {
        int v = 0;
        int mindist = INF;
        for (int j=0; j<=n; j++) {
            if (!sloved[j] && dist[j] < mindist) {
                v = j;
                mindist = dist[j];
            }
        }
        sloved[v] = true;
        for (int j=0; j<=n; j++) {
            if (!sloved[j] && g[v][j] < INF) {
                dist[j] = min(dist[j], g[v][j] + mindist);
            }
        }
    }
    shortest = dist[dest];
    return;
}

inline void init() {
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAXN; j++) {
            if (i != j) {
                g[i][j] = INF;
            }
            else {
                g[i][j] = 0;
            }
        }
    }
    return;
}

int main() {
    init();
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    cmax /= 2;
    for (int i=1; i<=n; i++) {
        scanf("%d", &store[i]);
    }
    while (m--) {
        int x, y, dist;
        scanf("%d%d%d", &x, &y, &dist);
        g[x][y] = dist;
        g[y][x] = dist;
    }
    dijk(0, sp);
    dfs();
    // printf("%d\n", shortest);
    printf("%d 0", minneed);
    for (int i=0; i<path.size(); i++){
        printf("->%d", path[i]);
    }
    printf(" %d\n", minremain);
    return 0;
}
