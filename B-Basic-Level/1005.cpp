#include <bits/stdc++.h>
using namespace std;
#define MAXN 101

bool pass[MAXN];
int a[MAXN];

int main() {
    memset(pass, 0, sizeof(pass));
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        int x = a[i];
        while (x != 1) {
            if (x % 2 == 0) {
                x /= 2;
            }
            else {
                x = ((3 * x) + 1) / 2;
            }
            if (x <= 100) {
                pass[x] = 1;
            }
        }
    }
    vector<int> num;
    for (int i=0; i<n; i++) {
        if (pass[a[i]] == 0) {
            num.push_back(a[i]);
        }
    }
    sort(num.begin(), num.end());
    for (int i=num.size()-1; i>0; i--) {
        printf("%d ", num[i]);
    }
    printf("%d", num[0]);
    return 0;
}
