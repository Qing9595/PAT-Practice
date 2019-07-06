#include <bits/stdc++.h>
using namespace std;
#define MAXN 500
#define INF 0x7FFFFFFF

int dMap[MAXN][MAXN], tMap[MAXN][MAXN];
int dPath[MAXN], dPathTemp[MAXN], tPath[MAXN], tPathTemp[MAXN];
bool dVisited[MAXN], tVisited[MAXN];
vector<int> dVector, tVector;
int dCost = 0, dCost_ = INF, tCost = 0, tCost_ = INF;

void copy_d(int vexnum) {
    for (int i=0; i<vexnum; i++) {
        dPath[i] = dPathTemp[i];
    }
}

void copy_t(int vexnum) {
    for (int i=0; i<vexnum; i++) {
        tPath[i] = tPathTemp[i];
    }
}

void getPath(int src, int dest) {
    int x = dest;
    while (x != src) {
        dVector.push_back(x);
        x = dPath[x];
    }
    dVector.push_back(src);
    x = dest;
    while (x != src) {
        tVector.push_back(x);
        x = tPath[x];
    }
    tVector.push_back(src);
}

void printans() {
    if (dVector == tVector) {
        printf("Distance = %d; Time = %d: ", dCost, tCost);
        for (int i=dVector.size()-1; i>0; i--) {
            printf("%d -> ", dVector[i]);
        }
        printf("%d", dVector[0]);
    }
    else {
        printf("Distance = %d: ", dCost);
        for (int i=dVector.size()-1; i>0; i--) {
            printf("%d -> ", dVector[i]);
        }
        printf("%d", dVector[0]);
        printf("\n");
        printf("Time = %d: ", tCost);
        for (int i=tVector.size()-1; i>0; i--) {
            printf("%d -> ", tVector[i]);
        }
        printf("%d", tVector[0]);
    }
}

void init() {
    for (int i=0; i<MAXN; i++) {
        dVisited[i] = false;
        tVisited[i] = false;
        for (int j=0; j<MAXN; j++) {
            if (i == j) {
                dMap[i][j] = 0;
                tMap[i][j] = 0;
            }
            else {
                dMap[i][j] = INF;
                tMap[i][j] = INF;
            }
        }
    }
}

void dijk_d(int vexnum, int src, int dest) {
    bool sloved[vexnum];
    int dist[vexnum];
    for (int i=0; i<vexnum; i++) {
        sloved[i] = false;
        dist[i] = dMap[src][i];
    }
    sloved[src] = true;
    int v;
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
            if (!sloved[j] && dMap[v][j] < INF) {
                if (dMap[v][j] + mindist < dist[j]) {
                    dist[j] = dMap[v][j] + mindist;
                    dPath[j] = v;
                }
            }
        }
    }
    dCost = dist[dest];
}

void dfs_d(int vexnum, int src, int dest, int cur_point, int cur_dist, int cur_time) {
    if (cur_point == dest && cur_dist == dCost) {
        if (cur_time < dCost_) {
            dCost_ = cur_time;
            copy_d(vexnum);
        }
        return;
    }
    if (cur_dist > dCost) {
        return;
    }
    for (int i=0; i<vexnum; i++) {
        if (!dVisited[i] && dMap[cur_point][i] < INF) {
            dVisited[i] = true;
            dPathTemp[i] = cur_point;
            dfs_d(vexnum, src, dest, i, cur_dist + dMap[cur_point][i], cur_time + tMap[cur_point][i]);
            dVisited[i] = false;
        }
    }
}

void dfs_d(int vexnum, int src, int dest) {
    dfs_d(vexnum, src, dest, src, 0, 0);
}

void dijk_t(int vexnum, int src, int dest) {
    bool sloved[vexnum];
    int time[vexnum];
    for (int i=0; i<vexnum; i++) {
        sloved[i] = false;
        time[i] = tMap[src][i];
    }
    sloved[src] = true;
    int v;
    for (int i=1; i<vexnum; i++) {
        int v = 0;
        int mintime = INF;
        for (int j=0; j<vexnum; j++) {
            if (!sloved[j] && time[j] < mintime) {
                v = j;
                mintime = time[j];
            }
        }
        sloved[v] = true;
        for (int j=0; j<vexnum; j++) {
            if (!sloved[j] && tMap[v][j] < INF) {
                if (tMap[v][j] + mintime < time[j]) {
                    time[j] = tMap[v][j] + mintime;
                    tPath[j] = v;
                }
            }
        }
    }
    tCost = time[dest];
}

void dfs_t(int vexnum, int src, int dest, int cur_point, int cur_dist, int num) {
    if (cur_point == dest && cur_dist == tCost) {
        if (num < tCost_) {
            tCost_ = num;
            copy_t(vexnum);
        }
        return;
    }
    if (cur_dist > tCost) {
        return;
    }
    for (int i=0; i<vexnum; i++) {
        if (!tVisited[i] && tMap[cur_point][i] < INF) {
            tVisited[i] = true;
            tPathTemp[i] = cur_point;
            dfs_t(vexnum, src, dest, i, cur_dist + tMap[cur_point][i], num + 1);
            tVisited[i] = false;
        }
    }
}

void dfs_t(int vexnum, int src, int dest) {
    dfs_t(vexnum, src, dest, src, 0, 0);
}

int main() {
    init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int x, y, one_way, dest, time;
        scanf("%d%d%d%d%d", &x, &y, &one_way, &dest, &time);
        dMap[x][y] = dest;
        tMap[x][y] = time;
        if (!one_way) {
            dMap[y][x] = dest;
            tMap[y][x] = time;
        }
    }
    int x, y;
    scanf("%d%d", &x, &y);
    dijk_d(n, x, y);
    dfs_d(n, x, y);
    dijk_t(n, x, y);
    dfs_t(n, x, y);
    getPath(x, y);
    printans();
    return 0;
}
