#include <bits/stdc++.h>
using namespace std;
set<int> sum;

int calc_sum(int x) {
    int res = 0;
    int tmp = x;
    while (tmp) {
        res += (tmp % 10);
        tmp /= 10;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    int x;
    for (int i=0; i<n; i++) {
        scanf("%d", &x);
        sum.insert(calc_sum(x));
    }
    int cnt = sum.size();
    printf("%d\n", cnt);
    set<int>::iterator iter = sum.begin();
    while (iter != sum.end() && cnt != 1) {
        cout<<*iter<<' ';
        iter++;
        cnt--;
    }
    printf("%d", *iter);
    return 0;
}
