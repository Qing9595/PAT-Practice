#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

struct node {
    int addr;
    int val;
    int next;
    bool valid;
};

node link[MAXN];
int cnt = 0;

void init() {
    for (int i=0; i<MAXN; i++) {
        link[i].valid = false;
    }
    return;
}

void visit(const int head) {
    int p = head;
    while (p != -1) {
        link[p].valid = true;
        cnt++;
        p = link[p].next;
    }
    return;
}

bool cmp(const node x, const node y) {
    if (x.valid != y.valid) return x.valid > y.valid;
    return x.val < y.val;
}

int main() {
    init();
    int head, n;
    scanf("%d%d", &n, &head);
    while (n--) {
        int addr, x, next;
        scanf("%d%d%d", &addr, &x, &next);
        link[addr].addr = addr;
        link[addr].val = x;
        link[addr].next = next;
    }
    visit(head);
    sort(link, link + MAXN, cmp);
    if (cnt == 0) {
        printf("0 -1\n");
        return 0;
    }
    printf("%d %05d\n", cnt, link[0].addr);
    for (int i=0; i<cnt-1; i++){
        printf("%05d %d %05d\n", link[i].addr, link[i].val, link[i + 1].addr);
    }
    printf("%05d %d -1\n", link[cnt - 1].addr, link[cnt - 1].val);
    return 0;
}
