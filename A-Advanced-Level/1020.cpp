#include <bits/stdc++.h>
using namespace std;
#define MAXN 30

struct node {
    int val;
    node *lc, *rc;
};

int post[MAXN], in[MAXN];
int n;
vector<int> level;

node* build(int postL, int postR, int inL, int inR) {
    if (postL > postR) {
        return NULL;
    }
    node *root = new node;
    root->val = post[postR];
    int k;
    for (k=inL; k<=inR; k++) {
        if (in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lc = build(postL, postL+numLeft-1, inL, k-1);
    root->rc = build(postL+numLeft, postR-1, k+1, inR);
    return root;
}

void level_order(node* t) {
    queue<node*> q;
    q.push(t);
    while (!q.empty()) {
        node *tmp = q.front();
        q.pop();
        level.push_back(tmp->val);
        if (tmp->lc != NULL) q.push(tmp->lc);
        if (tmp->rc != NULL) q.push(tmp->rc);
    }
    return;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &in[i]);
    }
    node *tree = build(0, n-1, 0, n-1);
    level_order(tree);
    for (int i=0; i<level.size(); i++) {
        printf("%d", level[i]);
        if (i != level.size()-1) printf(" ");
    }
    return 0;
}
