#include <bits/stdc++.h>
using namespace std;

string s;
map<string, int> cnt;

inline bool check(char c) {
    if (c >= '0' && c <= '9') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= 'a' && c <= 'z') return true;
    return false;
}

inline string to_lowercase(string str) {
    string res = "";
    for (int i=0; i<str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            res += (str[i] - 'A' + 'a');
        }
        else {
            res += str[i];
        }
    }
    return res;
}

inline void add_map(string word) {
    if (word == "") {return;}
    word = to_lowercase(word);
    if (cnt.find(word) == cnt.end()) {
        cnt[word] = 1;
    }
    else {
        cnt[word]++;
    }
    return;
}

int main() {
    getline(cin, s);
    int len = s.size();
    string word = "";
    for (int i=0; i<len; i++) {
        char c = s[i];
        if (i == len - 1) {
            if (check(c)) {word += c;}
            add_map(word);
            break;
        }
        if (check(c)) {
            word += c;
        }
        else if (word != "") {
            add_map(word);
            word.clear();
        }
    }
    map<string, int>::iterator iter, ans;
    int max_cnt = 0;
    for (iter=cnt.begin(); iter!=cnt.end(); iter++) {
        if (iter->second > max_cnt) {
            max_cnt = iter->second;
            ans = iter;
        }
    }
    cout << ans->first << ' ' << ans->second << endl;
    return 0;
}
