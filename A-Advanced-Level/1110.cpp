#include <bits/stdc++.h>
using namespace std;

struct node {
    int lc;
    int rc;
};

node t[21];
int last = 0;
set<int> temp;

bool level_order(int x) {
    bool first = false, flag = true;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (t[p].lc != -1) {
            q.push(t[p].lc);
        }
        if (t[p].rc != -1) {
            q.push(t[p].rc);
        }
        if (!first && ((t[p].lc != -1 && t[p].rc == -1) || (t[p].lc == -1 && t[p].rc == -1))) {
            first = true;
        }
        if (first && (t[p].lc != -1 || t[p].rc != -1)) {
            flag = false;
        }
        if (t[p].lc == -1 && t[p].rc != -1) {
            flag = false;
        }
        if (q.empty()) {
            last = p;
        }
    }
    return flag;
}

int in_order(int x) {
    int cnt = 0;
    if (x != -1) {
        in_order(t[x].lc);
        temp.insert(x);
        in_order(t[x].rc);
    }
    return temp.size();
}

int find_root(int n) {
    for (int i=0; i<n; i++) {
        temp.clear();
        if (n == in_order(i)) {
            return i;
        }
    }
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        string x, y;
        cin >> x >> y;
        if (x == "-") {
            t[i].lc = -1;
        }
        else {
            t[i].lc = atoi(x.c_str());
        }
        if (y == "-") {
            t[i].rc = -1;
        }
        else {
            t[i].rc = atoi(y.c_str());
        }
    }
    int root = find_root(n);
    if (level_order(root)) {
        printf("YES %d", last);
    }
    else {
        printf("NO %d", root);
    }
    return 0;
}
