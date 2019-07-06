#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

char a[] = "PATest";
char s[MAXN];
int len = 0;
multiset<char> pat;
set<char> PATest;

void init() {
    for (int i=0; i<strlen(a); i++) {
        PATest.insert(a[i]);
    }
    return;
}

int main() {
    init();
    scanf("%s", &s);
    len = strlen(s);
    int cnt = 0;
    for (int i=0; i<len; i++) {
        if (PATest.find(s[i]) != PATest.end()) {
            pat.insert(s[i]);
            cnt++;
        }
    }
    int p = 0;
    for (int i=0; i<cnt; ) {
        multiset<char>::iterator iter = pat.find(a[p % 6]);
        if (iter != pat.end()) {
            printf("%c", *iter);
            pat.erase(iter);
            i++;
            p++;
        }
        else {
            p++;
        }
    }
    return 0;
}
