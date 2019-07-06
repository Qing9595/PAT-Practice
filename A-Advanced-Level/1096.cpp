#include <bits/stdc++.h>
using namespace std;
#define LL long long

inline bool mod(LL data, LL x, LL y) {
    LL i = y, temp = data;
    while (i >= x) {
        if (temp % i == 0) {
            temp /= i;
            i--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    /*
    LL x;
    scanf("%lld", &x);

    LL last_index = x, first_index = x;
    LL cur_first = x, cur_last = x;

    bool flag = true;
    while (cur_first != 1) {
        if (mod(x, cur_first, cur_last)) {
            flag = true;
            if (cur_last - cur_first >= last_index - first_index) {
                first_index = cur_first;
                last_index = cur_last;
            }
            cur_first--;
        }
        else {
            if (flag) {
                cur_last--;
            }
            else {
                cur_first--;
                cur_last--;
            }
            flag = false;
        }
    }
    printf("%lld\n", last_index - first_index + 1);
    for (int i=first_index; i<last_index; i++) {
        printf("%lld*", i);
    }
    printf("%lld", last_index);
    */
    LL x;
    cin>>x;
    LL res=1;
    for (LL i=1;i<=x;i++){
        res*=i;
    }
    cout<<res;
    return 0;
}
