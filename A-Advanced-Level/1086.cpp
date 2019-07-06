#include <bits/stdc++.h>
using namespace std;
#define MAXN 30

struct node {
    int val;
    node *lc, *rc;
};

static stack<int> s;
static int n;
static int pre[MAXN], in[MAXN];
static vector<int> res;

node* build(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL;
    }
    node* root = new node;
    root->val = pre[preL];
    int k;
    for (k = inL; k<=inR; k++) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lc = build(preL+1, preL+numLeft, inL, k-1);
    root->rc = build(preL+numLeft+1, preR, k+1, inR);
    return root;
}

void post_travel(node* p) {
    if (p != NULL) {
        post_travel(p->lc);
        post_travel(p->rc);
        res.push_back(p->val);
    }
    return;
}

int main() {
    scanf("%d", &n);
    char op[5];
    int x;
    int pre_pos = 0, in_pos = 0;
    while (pre_pos != n || in_pos != n) {
        scanf("%s", &op);
        if (strcmp(op, "Push") == 0) {
            scanf("%d", &x);
            s.push(x);
            pre[pre_pos++] = x;
        }
        else {
            in[in_pos++] = s.top();
            s.pop();
        }
    }
    node* root = build(0, n-1, 0, n-1);
    post_travel(root);
    for (int i=0; i<res.size()-1; i++) {
        printf("%d ", res[i]);
    }
    printf("%d\n", res[res.size()-1]);
    return 0;
}
