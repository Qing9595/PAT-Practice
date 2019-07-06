#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int n;
int a[MAXN];
int leftMax[MAXN], rightMin[MAXN];
vector<int> res;

void init() {
    memset(leftMax, 0, sizeof(leftMax));
    memset(rightMin, 0, sizeof(rightMin));
    return;
}

int main() {
    init();
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    int num = 0;
    for (int i=1; i<n; i++) {
        leftMax[i] = num;
        if (a[i] > a[num]) {
            num = i;
        }
    }
    num = n - 1;
    for (int i=n-1; i>=0; i--) {
        rightMin[i] = num;
        if (a[i] < a[num]) {
            num = i;
        }
    }
    for (int i=0; i<n; i++) {
        if (a[i] >= a[leftMax[i]] && a[i] <= a[rightMin[i]]) {
            res.push_back(a[i]);
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    if (res.size() != 0) {
        for (int i=0; i<res.size()-1; i++) {
            printf("%d ", res[i]);
        }
        printf("%d\n", res[res.size()-1]);
    }
    else {
        printf("\n");
    }
    return 0;
}
