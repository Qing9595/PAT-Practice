#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

struct node {
    bool visited;
    int next;
};

node link[MAXN];

void visit(const int head) {
    int p = head;
    while (p != -1) {
        link[p].visited = true;
        p = link[p].next;
    }
    return;
}

int main() {
    int head1, head2, n;
    scanf("%d%d%d", &head1, &head2, &n);
    for (int i=0; i<n; i++) {
        int addr, next;
        char x;
        scanf("%d %c %d", &addr, &x, &next);
        link[addr].next = next;
        link[addr].visited = false;
    }
    visit(head1);
    int p = head2;
    while (p != -1) {
        if (link[p].visited) {break;}
        p = link[p].next;
    }
    if (p != -1) {
        printf("%05d\n", p);
    }
    else {
        printf("%d\n", p);
    }
    return 0;
}
