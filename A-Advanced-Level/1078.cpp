#include <bits/stdc++.h>
using namespace std;
#define MAXN 10010

static int n, m;
static bool hashTable[MAXN];

inline bool is_prime(int x) {
    if (x == 1) return false;
    int sqrtN = sqrt(x) + 0.5;
    for (int i=2; i<=sqrtN; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    memset(hashTable, 0, sizeof(hashTable));
    scanf("%d%d", &n, &m);
    while (!is_prime(n)) {
        n++;
    }
    int key;
    while (m--) {
        scanf("%d", &key);
        int h = key % n;
        bool flag = false;
        for (int i=0; i<n; i++) {
            int pos = (h + i * i) % n;
            if (!hashTable[pos]) {
                printf("%d", pos);
                flag = true;
                hashTable[pos] = true;
                break;
            }
        }
        if (!flag) {
            printf("-");
        }
        if (m != 0) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
