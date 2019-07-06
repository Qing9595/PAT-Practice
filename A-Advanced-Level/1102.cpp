#include <bits/stdc++.h>
using namespace std;
#define MAXN 10

struct node {
    int lc;
    int rc;
};

node t[MAXN];
vector<int> level_ans, in_ans;
set<int> temp;

void in_order0(int x) {
    if (x != -1) {
        in_order0(t[x].lc);
        temp.insert(x);
        in_order0(t[x].rc);
    }
}

int find_root(int node_cnt) {
    int i;
    for (i=0; i<node_cnt; i++) {
        temp.clear();
        in_order0(i);
        if (temp.size() == node_cnt) {
            break;
        }
    }
    return i;
}

void level_order(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        level_ans.push_back(p);
        if (t[p].lc != -1) {
            q.push(t[p].lc);
        }
        if (t[p].rc != -1) {
            q.push(t[p].rc);
        }
    }
}

void in_order(int x) {
    if (x != -1) {
        in_order(t[x].lc);
        in_ans.push_back(x);
        in_order(t[x].rc);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        char x, y;
        //scanf("%c%c", &x, &y);
        cin >> x >> y;
        if (x == '-') {
            t[i].rc = -1;
        }
        else {
            t[i].rc = x - '0';
        }
        if (y == '-') {
            t[i].lc = -1;
        }
        else {
            t[i].lc = y - '0';
        }
    }
    int root = find_root(n);
    level_order(root);
    in_order(root);
    for (int i=0; i<level_ans.size()-1; i++) {
        printf("%d ", level_ans[i]);
    }
    printf("%d\n", level_ans[level_ans.size()-1]);
    for (int i=0; i<in_ans.size()-1; i++) {
        printf("%d ", in_ans[i]);
    }
    printf("%d", in_ans[in_ans.size()-1]);
    return 0;
}
