/** Hash **/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int HashTable[MAXN];

int main() {
    memset(HashTable, 0, sizeof(HashTable));
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--) {
        int x;
        scanf("%d", &x);
        HashTable[x]++;
    }
    bool flag = false;
    for (int i=1; i<MAXN; i++) {
        if (HashTable[i] && HashTable[m - i] && i != m - i) {
            printf("%d %d", i, m - i);
            flag = true;
            break;
        }
        else if (i == m - i && HashTable[i] >= 2) {
            printf("%d %d", i, m - i);
            flag = true;
            break;
        }
    }
    if (!flag) {
        printf("No Solution");
    }
    return 0;
}
