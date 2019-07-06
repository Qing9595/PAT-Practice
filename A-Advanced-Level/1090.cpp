#include <bits/stdc++.h>
using namespace std;

struct node {
    int level;
    set<int> child;
};

static int n;
static double p, r;
static node* t;

inline int depth(int ptr) {
    if (t[ptr].child.empty()) {
        return 0;
    }
    int res = 0;
    set<int>::iterator iter;
    for (iter=t[ptr].child.begin(); iter!=t[ptr].child.end(); iter++) {
        res = max(res, depth(*iter));
    }
    return (res + 1);
}

inline void level_order(int ptr) {
    t[ptr].level = 0;
    queue<int> q;
    q.push(ptr);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        set<int>::iterator iter;
        for (iter=t[tmp].child.begin(); iter!=t[tmp].child.end(); iter++) {
            q.push(*iter);
            t[*iter].level = t[tmp].level + 1;
        }
    }
    return;
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    t = new node[n];
    static int root;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        if (x != -1) {
            t[x].child.insert(i);
        }
        else {
            root = i;
        }
    }
    int deep = depth(root);
    double ans = p * pow(1 + 0.01 * r, deep);
    level_order(root);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (t[i].level == deep) {
            cnt++;
        }
    }
    printf("%.2lf %d\n", ans, cnt);
    return 0;
}
