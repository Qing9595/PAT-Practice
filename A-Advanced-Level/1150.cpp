#include <bits/stdc++.h>
using namespace std;
#define MAXN 201

static int g[MAXN][MAXN];
static int n, m;


void init() {
    memset(g, 0, sizeof(g));
    return;
}

int calc_dist(const vector<int> &path) {
    int res = 0;
    for (int i=0; i<path.size()-1; i++) {
        if (g[path[i]][path[i+1] > 0) {
            res += g[path[i]][path[i+1]];
        }
        else {
            return 0;
        }
    }
    return res;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int c1, c2, dist;
        scanf("%d%d%d", &c1, &c2, &dist);
        g[c1][c2] = dist;
        g[c2][c1] = dist;
    }
    static int k;
    scanf("%d", &k);
    while (k--) {
        int t;
        scanf("%d", &t);
        vector<int> path;
        while (t--) {
            int x;
            scanf("%d", &x);
            path.push_back(x);
        }
    }
    return 0;
}
