#include <bits/stdc++.h>
using namespace std;
#define MAXN 31

struct node {
    char *val;
    int lc, rc;
};

static int n;
static node a[MAXN];
static int root = 0;
static vector<int> tmp;
static vector<string> tmp2;

void pre_travel(int src) {
    if (src != -1) {
        tmp.push_back(src);
        pre_travel(a[src].lc);
        pre_travel(a[src].rc);
    }
    return;
}

void in_travel(int src) {
    if (src != -1) {
        if (src != root && (a[src].lc != -1 || a[src].rc != -1))
            tmp2.push_back("(");
        in_travel(a[src].lc);
        tmp2.push_back(a[src].val);
        in_travel(a[src].rc);
        if (src != root && (a[src].lc != -1 || a[src].rc != -1))
            tmp2.push_back(")");
    }
    return;
}

int find_root() {
    for (int i=1; i<=n; i++) {
        tmp.clear();
        pre_travel(i);
        if (tmp.size() == n)
            return i;
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        char str[11];
        int lc, rc;
        scanf("%s%d%d", &str, &lc, &rc);
        a[i].val = new char[strlen(str) + 1];
        strcpy(a[i].val, str);
        a[i].lc = lc;
        a[i].rc = rc;
    }
    root = find_root();
    in_travel(root);
    for (int i=0; i<tmp2.size(); i++) {
        cout<<tmp2[i];
    }
    return 0;
}
