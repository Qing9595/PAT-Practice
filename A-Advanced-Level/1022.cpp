#include <bits/stdc++.h>
using namespace std;

struct node {
    int id;
    string title;
    string author;
    set<string> keywords;
    string publisher;
    int year;
};

bool operator < (const node &A, const node &B) {
    return A.id < B.id;
}

int n;
set<node> book;

inline set<string> split(string s) {
    set<string> keywords;
    string word = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] != ' ') {
            word += s[i];
        }
        else {
            keywords.insert(word);
            word.clear();
        }
    }
    keywords.insert(word);
    return keywords;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        node p;
        int id, year;
        string title, author, keywords, publisher;
        scanf("%d", &id);
        cin.get();
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        scanf("%d", &year);
        p.id = id;
        p.title = title;
        p.author = author;
        p.keywords = split(keywords);
        p.publisher = publisher;
        p.year = year;
        book.insert(p);
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int q;
        scanf("%d: ", &q);
        string str;
        getline(cin, str);
        int cnt = 0;
        set<node>::iterator iter;
        printf("%d: %s\n", q, str.c_str());
        switch (q) {
            case 1 : {
                for (iter=book.begin(); iter!=book.end(); iter++) {
                    if (iter->title == str) {
                        printf("%07d\n", iter->id);
                        cnt++;
                    }
                }
            } break;
            case 2 : {
                for (iter=book.begin(); iter!=book.end(); iter++) {
                    if (iter->author == str) {
                        printf("%07d\n", iter->id);
                        cnt++;
                    }
                }
            } break;
            case 3 : {
                for (iter=book.begin(); iter!=book.end(); iter++) {
                    if (iter->keywords.find(str) != iter->keywords.end()) {
                        printf("%07d\n", iter->id);
                        cnt++;
                    }
                }
            } break;
            case 4 : {
                for (iter=book.begin(); iter!=book.end(); iter++) {
                    if (iter->publisher == str) {
                        printf("%07d\n", iter->id);
                        cnt++;
                    }
                }
            } break;
            case 5 : {
                for (iter=book.begin(); iter!=book.end(); iter++) {
                    if (iter->year == atoi(str.c_str())) {
                        printf("%07d\n", iter->id);
                        cnt++;
                    }
                }
            } break;
        }
        if (cnt == 0) {printf("Not Found\n");}
    }
    return 0;
}
