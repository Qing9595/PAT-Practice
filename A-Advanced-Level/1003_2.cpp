#include <bits/stdc++.h>
using namespace std;
#define MAXN 500
#define INF INT_MAX

int graph[MAXN][MAXN];
int team[MAXN];
bool visited[MAXN];
int vexnum = MAXN, shortest = INF, cnt = 0, maxTeam = 0;

void init() {
    for (int i=0; i<vexnum; i++) {
        visited[i] = false;
        for (int j=0; j<vexnum; j++) {
            if (i != j) {
                graph[i][j] = INF;
            }
            else {
                graph[i][j] = 0;
            }
        }
    }
}

void dfs(int src, int dest, int cur_point, int cur_dist, int cur_team) {
    if (cur_point == dest) {
        if (cur_dist < shortest) {
            shortest = cur_dist;
            cnt = 1;
            maxTeam = cur_team;
        }
        else if (cur_dist == shortest) {
            cnt++;
            maxTeam = max(maxTeam, cur_team);
        }
        return;
    }
    if (cur_dist > shortest) {
        return;
    }
    for (int i=0; i<vexnum; i++) {
        if (!visited[i] && graph[cur_point][i] < INF) {
            visited[i] = true;
            dfs(src, dest, i, cur_dist + graph[cur_point][i], cur_team + team[i]);
            visited[i] = false;
        }
    }
}

void dfs(int src, int dest) {
    dfs(src, dest, src, 0, 0);
}

int main() {
    int m, c1, c2;
    scanf("%d%d%d%d", &vexnum, &m, &c1, &c2);
    init();
    for (int i=0; i<vexnum; i++) {
        scanf("%d", &team[i]);
    }
    while (m--) {
        int x, y, dist;
        scanf("%d%d%d", &x, &y, &dist);
        graph[x][y] = dist;
        graph[y][x] = dist;
    }
    dfs(c1, c2);
    printf("%d %d", cnt, maxTeam);
    return 0;
}
