#include <bits/stdc++.h>
using namespace std;

struct node {
    int level;
    set<int> child;
};

static int n, m;
static node* t;
static int* hashTable;

inline void level_order(int p) {
    t[p].level = 1;
    queue<int> q;
    q.push(p);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        set<int>::iterator iter;
        for (iter=t[tmp].child.begin(); iter!=t[tmp].child.end(); iter++) {
            q.push(*iter);
            t[*iter].level = t[tmp].level + 1;
        }
    }
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    t = new node[n + 1];
    hashTable = new int[n + 1];
    memset(hashTable, 0, (n + 1) * sizeof(int));
    for (int i=0; i<m; i++) {
        int id, k;
        scanf("%d%d", &id, &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            t[id].child.insert(x);
        }
    }
    level_order(1);
    for (int i=1; i<=n; i++) {
        hashTable[t[i].level]++;
    }
    delete [] t;
    int num = 1;
    for (int i=1; i<=n; i++) {
        if (hashTable[num] < hashTable[i]) {
            num = i;
        }
    }
    printf("%d %d\n", hashTable[num], num);
    return 0;
}
