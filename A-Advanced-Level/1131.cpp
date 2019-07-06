#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define MAXN 10000

vector<int> subway[MAXN];
map<pair<int, int>, int> line;
vector<int> path, tmpPath;
int n;
int mindist = INF, mintrans = INF;
bool vis[MAXN];
int src, dest;

inline int calc_trans(vector<int> v) {
    int res = 0;
    int pre_line = line[pair<int, int>(src, v[0])];
    for (int i=1; i<v.size(); i++) {
        int cur_line = line[pair<int, int>(v[i], v[i-1])];
        if (cur_line != pre_line) {res++;}
        pre_line = cur_line;
    }
    return res;
}

void dfs(int cur_point, int cur_dist) {
    if (cur_dist > mindist) {
        return;
    }
    if (cur_point == dest) {
        if (cur_dist < mindist) {
            path = tmpPath;
            mindist = cur_dist;
            mintrans = calc_trans(path);
            return;
        }
        if (cur_dist == mindist && calc_trans(tmpPath) < mintrans) {
            path = tmpPath;
            mintrans = calc_trans(path);
            return;
        }
        return;
    }
    for (int i=0; i<subway[cur_point].size(); i++) {
        if (!vis[subway[cur_point][i]]) {
            vis[subway[cur_point][i]] = true;
            tmpPath.push_back(subway[cur_point][i]);
            dfs(subway[cur_point][i], cur_dist + 1);
            tmpPath.pop_back();
            vis[subway[cur_point][i]] = false;
        }
    }
    return;
}

inline void print_ans() {
    printf("%d\n", mindist);
    int pre_line = line[pair<int, int>(src, path[0])];
    int pos = src;
    for (int i=1; i<path.size(); i++) {
        int cur_line = line[pair<int, int>(path[i], path[i-1])];
        if (cur_line != pre_line) {
            printf("Take Line#%d from %04d to %04d.\n", pre_line, pos, path[i-1]);
            pos = path[i-1];
        }
        pre_line = cur_line;
    }
    printf("Take Line#%d from %04d to %04d.\n", pre_line, pos, path[path.size()-1]);
    return;
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        int m;
        scanf("%d", &m);
        int temp[m];
        for (int j=0; j<m; j++) {
            scanf("%d", &temp[j]);
            if(j != 0){
                subway[temp[j-1]].push_back(temp[j]);
                subway[temp[j]].push_back(temp[j-1]);
                line[pair<int, int>(temp[j-1], temp[j])] = i;
                line[pair<int, int>(temp[j], temp[j-1])] = i;
            }
        }
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        memset(vis, 0, sizeof(vis));
        path.clear();
        tmpPath.clear();
        mindist = INF;
        mintrans = INF;
        scanf("%d%d", &src, &dest);
        vis[src] = true;
        dfs(src, 0);
        print_ans();
    }
    return 0;
}
