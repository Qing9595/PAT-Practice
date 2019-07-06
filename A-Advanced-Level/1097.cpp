#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    int next;
};

node link[100002]; // Í·½Úµã
set<int> num;
int cur_head = 100000;
int new_head = 100001;

bool set_contains(int x) {
    set<int>::iterator iter;
    iter = num.find(x);
    return (iter == num.end() ? false : true);
}

void remove_ele() {
    int x = cur_head, y = new_head;
    while (link[x].next != -1) {
        int val = link[link[x].next].data;
        if (!set_contains(abs(val))) {
            num.insert(abs(val));
            x = link[x].next;
        }
        else {
            link[y].next = link[x].next;
            y = link[y].next;
            link[x].next = link[y].next;
            link[y].next = -1;
            // x = link[x].next;
        }
    }
}

void print_list(int head) {
    int x = link[head].next;
    if (x != -1) {
        while (link[x].next != -1) {
            printf("%05d %d %05d\n", x, link[x].data, link[x].next);
            x = link[x].next;
        }
        printf("%05d %d -1\n", x, link[x].data);
    }
}

int main() {
    int head, n;
    scanf("%d%d", &head, &n);
    link[cur_head].next = head;
    link[new_head].next = -1;
    for (int i=0; i<n; i++) {
        int add, val, ptr;
        scanf("%d%d%d", &add, &val, &ptr);
        link[add].data = val;
        link[add].next = ptr;
    }
    remove_ele();
    print_list(cur_head);
    print_list(new_head);
    return 0;
}
