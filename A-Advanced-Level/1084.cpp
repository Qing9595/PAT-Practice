#include <bits/stdc++.h>
using namespace std;

set<char> broken;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int p1 = 0, p2 = 0;
    while (p1 < s1.length()) {
        if (s1[p1] != s2[p2]) {
            if (broken.find(s1[p1]) == broken.end()) {
                if (s1[p1] >= 'a' && s1[p1] <= 'z') {
                    printf("%c", s1[p1] - 'a' + 'A');
                    broken.insert(s1[p1] - 'a' + 'A');
                    broken.insert(s1[p1]);
                }
                else if (s1[p1] >= 'A' && s1[p1] <= 'Z') {
                    printf("%c", s1[p1]);
                    broken.insert(s1[p1]);
                    broken.insert(s1[p1] - 'A' + 'a');
                }
                else {
                    printf("%c", s1[p1]);
                    broken.insert(s1[p1]);
                }
                p1++;
            }
            else {
                p1++;
            }
        }
        else {
            p1++;
            p2++;
        }
    }
    return 0;
}
