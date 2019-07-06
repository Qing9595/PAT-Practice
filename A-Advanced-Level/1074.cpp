#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

struct node {
    int val;
    int next;
};

node link[MAXN];

int reverse_link(int pre, const int first, const int last) {
    int cur = link[first].next;
    int head = pre, next;
    pre = first;
    int x = link[last].next;
    while (cur != x) {
        next = link[cur].next;
        link[cur].next = pre;
        pre = cur;
        cur = next;
    }
    link[head].next = pre;
    link[first].next = cur;
    return first;
}

void print_ans(const int head) {
    int p = head;
    while (link[p].next != -1) {
        printf("%05d %d %05d\n", p, link[p].val, link[p].next);
        p = link[p].next;
    }
    printf("%05d %d %d", p, link[p].val, link[p].next);
    return;
}

int main() {
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);
    for (int i=0; i<n; i++) {
        int addr, x, next;
        scanf("%d%d%d", &addr, &x, &next);
        link[addr].val = x;
        link[addr].next = next;
    }
    const int my_head = 100000;
    link[my_head].next = head;
    int pre, first, last, p = my_head;
    bool flag = false;
    while (link[p].next != -1) {
        pre = p;
        p = link[p].next;
        first = p;
        int cnt = 1;
        for (; cnt<k; cnt++) {
            p = link[p].next;
            if (p == -1) {break;}
        }
        if (cnt < k) {break;}
        last = p;
        p = reverse_link(pre, first, last);
        if (!flag) {
            head = last;
            flag = true;
        }
    }
    print_ans(head);
    return 0;
}
