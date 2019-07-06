#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

struct node {
    int weight;
    int r;
};

int np, ng;
node mouse[MAXN];
queue<int> q;

void calc(int group_index, int group_size, int cur) {
    int loop;
    if (group_index * ng - 1 + ng < cur) loop = ng;
    else loop = cur - group_index * ng;
    int k = q.front();
    while (loop--) {
        int p = q.front();
        q.pop();
        if (mouse[p].weight > mouse[k].weight) {
            k = p;
        }
        mouse[p].r = group_size + 1;
    }
    q.push(k);
    return;
}

int main() {
    scanf("%d%d", &np, &ng);
    for (int i=0; i<np; i++) {
        scanf("%d", &mouse[i].weight);
    }
    for (int i=0; i<np; i++) {
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    int cur = np, group_size = 0;
    while (q.size() != 1) {
        if (cur % ng) group_size = cur / ng + 1;
        else group_size = cur / ng;
        for (int i=0; i<group_size; i++) {
            calc(i, group_size, cur);
        }
        cur = group_size;
    }
    mouse[q.front()].r = 1;
    for (int i=0; i<np; i++) {
        printf("%d", mouse[i].r);
        if (i < np - 1) printf(" ");
    }
    return 0;
}
