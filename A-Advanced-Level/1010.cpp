#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL INF = LONG_LONG_MAX;
LL known, r;
string unknown;

map<char, int> myMap;

inline void init() {
    for (int i=0; i<10; i++){
        myMap.insert(pair<char,int>('0' + i, i));
    }
    for (int i=10; i<16; i++){
        myMap.insert(pair<char,int>('a' + i - 10, i));
    }
    return;
}

/*
LL get_dec(string x, LL radix, LL limit) {
    LL ans = 0;
    for (int i=0; i<x.length()-1; i++) {
        ans = (ans + myMap[x[i]]) * radix;
        if (ans < 0 || ans > limit) {return -1;}
    }
    char c = x[x.length()-1];
    ans += myMap[c];
    return (ans < 0 || ans > limit ? -1 : ans);
}
*/

LL get_dec(string x, LL radix, LL limit) {
    LL ans = 0;
    for (int i=0; i<x.length(); i++) {
        ans = (ans * radix) + myMap[x[i]];
        if (ans < 0 || ans > limit) {return -1;}
    }
    return ans;
}

int findLargest(string s) {
    int ans = -1;
    for (int i=0; i<s.length(); i++) {
        ans = max(myMap[s[i]], ans);
    }
    return ans;
}

int cmp(string s, LL r, LL limit) {
    LL temp = get_dec(s, r, limit);
    if (temp < 0) return 1;
    if (limit > temp) return -1;
    if (limit == temp) return 0;
    return 1;
}

LL binary(string s, LL left, LL right, LL limit) {
    LL mid;
    while (left <= right) {
        mid = (left + right) / 2;
        int flag = cmp(s, mid, limit);
        if (flag == 0) return mid;
        if (flag == 1) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    init();
    string s1, s2;
    int tag = 1;
    cin >> s1 >> s2 >> tag >> r;
    if (s1 == "1" && s2 == "1") {
        printf("2\n");
        return 0;
    }
    if (s1 == s2 && s1 != "1") {
        printf("%lld\n", r);
        return 0;
    }
    if (tag == 1) {
        known = get_dec(s1, r, INF);
        unknown = s2;
    } else {
        known = get_dec(s2, r, INF);
        unknown = s1;
    }
    LL low = findLargest(unknown) + 1;
    LL high = max(low, known) + 1;
    LL ans = binary(unknown, low, high, known);
    if (ans == -1) {printf("Impossible\n");}
    else {printf("%lld\n", ans);}
    return 0;
}
