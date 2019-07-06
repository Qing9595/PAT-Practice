#include <bits/stdc++.h>
using namespace std;

struct node {
    int weight;
    vector<int> child;
};

static int n, m, s;
static node* t;
static multiset<vector<int> > path;
static vector<int> tmp;
static bool* vis;

inline bool is_leaf(const int &x) {
    if (t[x].child.empty()) {
        return true;
    }
    return false;
}

void dfs(int cur_point, int cur_weight) {
    vis[cur_point] = true;
    if (cur_weight > s) {
        return;
    }
    if (is_leaf(cur_point) && cur_weight == s) {
        path.insert(tmp);
        return;
    }
    for (int i=0; i<t[cur_point].child.size(); i++) {
        const int child = t[cur_point].child[i];
        if (!vis[child]) {
            vis[child] = true;
            tmp.push_back(t[child].weight);
            dfs(child, cur_weight + t[child].weight);
            tmp.pop_back();
            vis[child] = false;
        }
    }
    return;
}

inline void print_ans(const multiset<vector<int> >::iterator &iter) {
    printf("%d", t[0].weight);
    for (int i=0; i<(*iter).size(); i++) {
        printf(" %d", (*iter)[i]);
    }
    printf("\n");
    return;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    t = new node[n];

    for (int i=0; i<n; i++) {
        int w;
        scanf("%d", &w);
        t[i].weight = w;
    }
    for (int i=0; i<m; i++) {
        int id, k;
        scanf("%d%d", &id, &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            t[id].child.push_back(x);
        }
    }
    vis = new bool[n];
    memset(vis, 0, n * sizeof(bool));
    dfs(0, t[0].weight);

    multiset<vector<int> >::iterator iter = --path.end();
    for (; iter!=path.begin(); iter--) {
        print_ans(iter);
    }
    print_ans(path.begin());
    return 0;
}
