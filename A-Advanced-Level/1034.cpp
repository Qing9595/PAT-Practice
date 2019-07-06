#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000

static int n, k, cnt = 0;
static set<string> person;
static int g[MAXN][MAXN];
static int w[MAXN];
static map<string, int> str2int;
static map<int, string> int2str;
static bool vis[MAXN];

struct node {
    string head;
    int member;
};

static int head;
static int member = 0;
static int edge = 0; //±ßÈ¨ºÏ¼Æ
static set<pair<int, int> > visedge;
static vector<node> gang;


void dfs(int s) {
    vis[s] = true;
    member++;
    if (w[s] > w[head]) {
        head = s;
    }
    for (int i=0; i<cnt; i++) {
        if (g[s][i] && visedge.find(pair<int, int>(s, i)) == visedge.end()) {
            edge += g[s][i];
            visedge.insert(pair<int, int>(s, i));
            visedge.insert(pair<int, int>(i, s));
        }
        if (!vis[i] && g[s][i]) {
            dfs(i);
        }
    }
    return;
}

bool cmp(const node &x, const node &y) {
    return x.head < y.head;
}

int main() {
    memset(g, 0, sizeof(g));
    memset(w, 0, sizeof(w));
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &k);
    string str1, str2;
    int time;
    for (int i=0; i<n; i++) {
        cin >> str1 >> str2;
        scanf("%d", &time);
        int x, y;
        if (person.find(str1) == person.end()) {
            person.insert(str1);
            str2int[str1] = cnt;
            int2str[cnt] = str1;
            cnt++;
        }
        if (person.find(str2) == person.end()) {
            person.insert(str2);
            str2int[str2] = cnt;
            int2str[cnt] = str2;
            cnt++;
        }
        x = str2int[str1];
        y = str2int[str2];
        g[x][y] += time;
        g[y][x] += time;
        w[x] += time;
        w[y] += time;
    }
    for (int i=0; i<cnt; i++) {
        if (!vis[i]) {
            head = i;
            member = 0;
            edge = 0;
            visedge.clear();
            dfs(i);
            if (edge > k && member > 2) {
                node p;
                p.head = int2str[head];
                p.member = member;
                gang.push_back(p);
            }
        }
    }
    sort(gang.begin(), gang.end(), cmp);
    printf("%d\n", gang.size());
    for (int i=0; i<gang.size(); i++) {
        cout << gang[i].head << ' ' << gang[i].member << endl;
    }
    return 0;
}
