#include <bits/stdc++.h>
using namespace std;
#define MAXN 1011
#define INF INT_MAX

static int n, m, k, d, vex;
static int g[MAXN][MAXN];

static int total =  INF, lowest = -1;

inline int str2int(const string &s) {
    if (s[0] == 'G') {
        return atoi(s.substr(1).c_str()) + n;
    }
    return atoi(s.c_str());
}

bool dijk(int s) {
    int dist[vex + 1];
    bool sloved[vex + 1];
    for (int i=1; i<=vex; i++) {
        dist[i] = g[s][i];
    }
    memset(sloved, 0, sizeof(sloved));
    sloved[s] = true;
    for (int i=1; i<vex; i++) {
        int mindist = INF;
        int v = 1;
        for (int j=1; j<=vex; j++) {
            if (!sloved[j] && dist[j] < mindist) {
                v = j;
                mindist = dist[j];
            }
        }
        sloved[v] = true;
        for (int j=1; j<=m+n; j++) {
            if (!sloved[j] && g[v][j] < INF) {
                dist[j] = min(dist[j], g[v][j] + mindist);
            }
        }
    }
    int _total = 0, _lowest = INF;
    for (int i=1; i<=n; i++) {
        _total += dist[i];
        _lowest = min(_lowest, dist[i]);
        if (dist[i] > d) {
            return false;
        }
    }
    if (_lowest > lowest) {
        lowest = _lowest;
        total = _total;
        return true;
    }
    if (_lowest == lowest && _total < total) {
        lowest = _lowest;
        total = _total;
        return true;
    }
    return false;
}

inline void init() {
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
    scanf("%d%d%d%d", &n, &m, &k, &d);
    vex = n + m;
    while (k--) {
        string s1, s2;
        int x, y, dis;
        cin >> s1 >> s2;
        scanf("%d", &dis);
        x = str2int(s1);
        y = str2int(s2);
        g[x][y] = dis;
        g[y][x] = dis;
    }
    int num = n + 1;
    int res = -1;
    while (num <= n + m) {
        if (dijk(num)) {
            res = num;
        }
        num++;
    }
    if (res != -1) {
        printf("G%d\n", res - n);
        printf("%.1lf %.1lf\n", double(lowest), double(total) / n);
    }
    else {
        printf("No Solution\n");
    }
    return 0;
}
