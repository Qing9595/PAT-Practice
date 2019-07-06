/** dijk + dfs**/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200
#define INF INT_MAX

static int n, k;
static string src;
static int g[MAXN][MAXN], happiness[MAXN];
static map<string, int> m1;
static map<int, string> m2;

static int cnt = 0, shortest = INF, maxhappiness = -1;
static vector<int> tmppath, path;
static bool vis[MAXN];

void dfs(const int &cur_point, const int &cur_dist, const int &cur_happiness) {
    if (cur_dist > shortest) {
        return;
    }
    if (cur_point == m1["ROM"] && cur_dist == shortest) {
        cnt++;
        if (cur_happiness > maxhappiness) {
            shortest = cur_dist;
            maxhappiness = cur_happiness;
            path = tmppath;
            return;
        }
        if (cur_happiness == maxhappiness && tmppath.size() < path.size()) {
            maxhappiness = cur_happiness;
            path = tmppath;
            return;
        }
        return;
    }
    for (int i=0; i<n; i++) {
        if (!vis[i] && g[cur_point][i] < INF) {
            vis[i] = true;
            tmppath.push_back(i);
            dfs(i, cur_dist + g[cur_point][i], cur_happiness + happiness[i]);
            tmppath.pop_back();
            vis[i] = false;
        }
    }
    return;
}

void dijk(const int &s) {
    int dist[n];
    bool sloved[n];
    memset(sloved, 0, sizeof(sloved));
    for (int i=0; i<n; i++) {
        dist[i] = g[s][i];
    }
    sloved[s] = true;
    for (int i=1; i<n; i++) {
        int mindist = INF;
        int v;
        for (int j=0; j<n; j++) {
            if (!sloved[j] && dist[j] < mindist) {
                mindist = dist[j];
                v = j;
            }
        }
        sloved[v] = true;
        for (int j=0; j<n; j++) {
            if (!sloved[j] && g[v][j] < INF) {
                dist[j] = min(dist[j], g[v][j] + mindist);
            }
        }
    }
    shortest = dist[m1["ROM"]];
    return;
}

int main() {
    memset(vis, 0, sizeof(vis));
    fill(g[0], g[0] + MAXN * MAXN, INF);
    cin >> n >> k >> src;
    m1[src] = 0;
    m2[0] = src;
    for (int i=1; i<n; i++) {
        string city;
        int happy;
        cin >> city >> happy;
        m1[city] = i;
        m2[i] = city;
        happiness[i] = happy;
    }
    while (k--) {
        string c1, c2;
        int dis;
        cin >> c1 >> c2 >> dis;
        g[m1[c1]][m1[c2]] = dis;
        g[m1[c2]][m1[c1]] = dis;
    }
    dijk(m1[src]);
    vis[m1[src]] = true;
    dfs(m1[src], 0, 0);
    cout << cnt << ' ' << shortest << ' ' << maxhappiness << ' ' << maxhappiness / path.size() << endl;
    cout << src;
    for (int i=0; i<path.size(); i++) {
        cout << "->" << m2[path[i]];
    }
    cout << endl;
    return 0;
}
