#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001

static set<int> g[MAXN];
static bool vis[MAXN];
static int n;

static int level[MAXN];
static set<int> root;

inline void dfs(const int &s) {
    vis[s] = true;
    set<int>::iterator iter;
    for (iter=g[s].begin(); iter!=g[s].end(); iter++) {
        if (!vis[*iter]) {
            dfs(*iter);
        }
    }
    return;
}

inline void bfs(const int &s) {
    memset(vis, 0, sizeof(vis));
    memset(level, 0, sizeof(level));
    int max_height = 0;
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        set<int>::iterator iter;
        for (iter=g[tmp].begin(); iter!=g[tmp].end(); iter++) {
            if (!vis[*iter]) {
                vis[*iter] = true;
                q.push(*iter);
                level[*iter] = level[tmp] + 1;
                max_height = max(max_height, level[*iter]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (level[i] == max_height) {
            root.insert(i);
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].insert(y);
        g[y].insert(x);
    }
    int component = 0;
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            dfs(i);
            component++;
        }
    }
    if (component > 1) {
        printf("Error: %d components\n", component);
    }
    else {
        bfs(1);
        set<int>::iterator iter;

        for (iter=root.begin(); iter!=root.end(); iter++) {
            bfs(*iter);
        }

        for (iter=root.begin(); iter!=root.end(); iter++) {
            printf("%d\n", *iter);
        }
    }
    return 0;
}
