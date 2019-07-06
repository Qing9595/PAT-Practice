#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

static int n, l;
static bool g[MAXN][MAXN];
static bool enqueue[MAXN];

struct node {
    int num;
    int level;
};

int bfs(const int &s) {
    queue<node> q;
    node src;
    src.num = s;
    src.level = 0;
    q.push(src);
    enqueue[s] = true;
    int cnt = 0;
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        if (p.level > l) {
            break;
        }
        cnt++;
        for (int i=1; i<=n; i++) {
            if (g[p.num][i] && !enqueue[i]) {
                node tmp;
                tmp.num = i;
                tmp.level = p.level + 1;
                q.push(tmp);
                enqueue[i] = true;
            }
        }
    }
    return cnt - 1;
}

int main() {
    memset(g, 0, sizeof(g));
    scanf("%d%d", &n, &l);
    for (int i=1; i<=n; i++) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            g[x][i] = true;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        memset(enqueue, 0, sizeof(enqueue));
        printf("%d\n", bfs(x));
    }
    return 0;
}
