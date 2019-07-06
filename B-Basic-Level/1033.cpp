#include <bits/stdc++.h>
using namespace std;

set<char> broken;

int main() {
    char str[128];
    gets(str);
    // scanf("%s", &str);
    for (int i=0; i<strlen(str); i++) {
        broken.insert(str[i]);
    }
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            if (broken.find('+') == broken.end() && broken.find(c) == broken.end()) {
                printf("%c", c);
            }
        }
        else if (c >= 'a' && c <= 'z') {
            if (broken.find(c - 'a' + 'A') == broken.end()) {
                printf("%c", c);
            }
        }
        else if (broken.find(c) == broken.end()) {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
