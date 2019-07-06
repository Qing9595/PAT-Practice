#include <bits/stdc++.h>
using namespace std;
/** begin at - 09:14 **/

#define MAXN 500
#define INF 0x7FFFFFFF

int graph[MAXN][MAXN];
int team[MAXN];
bool visited[MAXN];
int shortest = INF;
int shortestCnt = 0;
int maxTeam = 0;

void init() {
    for (int i=0; i<MAXN; i++) {
        visited[i] = false;
        for (int j=0; j<MAXN; j++) {
            if (i != j) {
                graph[i][j] = INF;
            }
            else {
                graph[i][j] = 0;
            }
        }
    }
}

int calc_team(int path[], int src, int dest) {
    int x = dest;
    int num = 0;
    while (path[x] != x) {
        num += team[x];
        x = path[x];
    }
    if (x == src) {
        return num + team[src];
    }
    return -1;
}

void dijk(int vexnum, int src, int dest) {
    bool sloved[vexnum];
    int dist[vexnum];
    for (int i=0; i<vexnum; i++) {
        sloved[i] = false;
        dist[i] = graph[src][i];
    }
    sloved[src] = true;
    for (int i=1; i<vexnum; i++) {
        int v = 0;
        int mindist = INF;
        for (int j=0; j<vexnum; j++) {
            if (!sloved[j] && dist[j] < mindist) {
                v = j;
                mindist = dist[j];
            }
        }
        sloved[v] = true;
        for (int j=0; j<vexnum; j++) {
            if (!sloved[j] && graph[v][j] < INF) {
                if (graph[v][j] + mindist < dist[j]) {
                    dist[j] = graph[v][j] + mindist;
                }
            }
        }
    }
    shortest = dist[dest];
}

void dfs(int vexnum, int src, int dest, int cur_point, int cur_dist, int cur_sum) {
    if (cur_point == dest && shortest == cur_dist) {
        shortestCnt++;
        maxTeam = max(maxTeam, cur_sum);
        return;
    }
    if (cur_dist > shortest) {
        return;
    }
    for (int i=0; i<vexnum; i++) {
        if (!visited[i] && graph[cur_point][i] < INF) {
            visited[i] = true;
            dfs(vexnum, src, dest, i, cur_dist + graph[cur_point][i], cur_sum + team[i]);
            visited[i] = false;
        }
    }
}

void dfs(int vexnum, int src, int dest) {
    visited[src] = true;
    dfs(vexnum, src, dest, src, 0, team[src]);
}

int main() {
    init();
    int n, m, c1, c2;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i=0; i<n; i++) {
        scanf("%d", &team[i]);
    }
    for (int i=0; i<m; i++) {
        int x, y, dist;
        scanf("%d%d%d", &x, &y, &dist);
        graph[x][y] = dist;
        graph[y][x] = dist;
    }
    dijk(n, c1, c2);
    dfs(n, c1, c2);
    printf("%d %d", shortestCnt, maxTeam);
    return 0;
}
