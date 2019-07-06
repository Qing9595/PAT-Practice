#include <bits/stdc++.h>
using namespace std;

int n, k, p;
vector<int> fac;
int max_fac = -1;

vector<int> tmp, ans;

void calc_fac() {
    // x ^ p;
    int x = 0, res = 0;
    while (res <= n) {
        res = pow(x++, p) + 1e-5;
        fac.push_back(res);
    }
    return;
}

void dfs(int cur, int cur_num, int cur_sum, int fac_sum) {
    if (cur_num > k || cur_sum > n) {
        return;
    }
    if (cur_num == k && cur_sum == n) {
        if (fac_sum > max_fac) {
            max_fac = fac_sum;
            ans = tmp;
        }
        return;
    }
    if (cur >= 1) {
        tmp.push_back(cur);
        dfs(cur, cur_num + 1, cur_sum + fac[cur], fac_sum + cur);
        tmp.pop_back();
        dfs(cur - 1, cur_num, cur_sum, fac_sum);
    }
    return;
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    calc_fac();
    dfs(fac.size() - 1, 0, 0, 0);
    if (max_fac != -1) {
        printf("%d =", n);
        for (int i=0; i<ans.size()-1; i++) {
            printf(" %d^%d +", ans[i], p);
        }
        printf(" %d^%d\n", ans[ans.size()-1], p);
    }
    else {
        printf("Impossible\n");
    }
    return 0;
}
