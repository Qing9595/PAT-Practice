#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

struct node {
    int link;
    int estate;
    int area;
};

struct fnode {
    int host;
    int cnt_estate;
    int cnt_area;
    float avg_sets, avg_area;
    set<int> people;
};

set<int> card;
vector<fnode> family;

node people[MAXN];

void init() {
    for (int i=0; i<MAXN; i++) {
        people[i].link = i;
        people[i].estate = 0;
        people[i].area = 0;
    }
}

int set_find(int x) {
    while (people[x].link != x) {
        x = people[x].link;
    }
    return x;
}

void set_join(int x, int y) {
    int fx = set_find(x);
    int fy = set_find(y);
    if (fx != fy) {
        if (fx < fy) {
            people[fy].link = fx;
        }
        else {
            people[fx].link = fy;
        }
    }
}

bool cmp(fnode x, fnode y) {
    if (x.avg_area == y.avg_area) {
        return x.host < y.host;
    }
    return x.avg_area > y.avg_area;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int id, father, mother;
        scanf("%d%d%d", &id, &father, &mother);
        card.insert(id);
        if (father != -1) {
            card.insert(father);
            set_join(id, father);
        }
        if (mother != -1) {
            card.insert(mother);
            set_join(id, mother);
        }
        int k;
        scanf("%d", &k);
        int child[k];
        for (int j=0; j<k; j++) {
            int x;
            scanf("%d", &x);
            card.insert(x);
            child[j] = x;
            set_join(id, x);
        }
        int estate, area;
        scanf("%d%d", &estate, &area);
        people[id].estate = estate;
        people[id].area = area;
    }
    set<int>::iterator iter;
    for (iter=card.begin(); iter!=card.end(); iter++) {
        bool flag = false;
        for (int j=0; j<family.size(); j++) {
            if (family[j].host == set_find(*iter)) {
                flag = true;
                family[j].cnt_estate += people[*iter].estate;
                family[j].cnt_area += people[*iter].area;
                family[j].people.insert(*iter);
            }
        }
        if (!flag) {
            fnode p;
            p.host = set_find(*iter);
            p.cnt_estate = people[*iter].estate;
            p.cnt_area = people[*iter].area;
            p.people.insert(*iter);
            family.push_back(p);
        }
    }
    printf("%d\n", family.size());
    for (int i=0; i<family.size(); i++) {
        family[i].avg_sets = float(family[i].cnt_estate)/family[i].people.size();
        family[i].avg_area = float(family[i].cnt_area)/family[i].people.size();
    }
    sort(family.begin(), family.end(), cmp);
    for (int i=0; i<family.size(); i++) {
        printf("%04d %d %.3f %.3f\n", family[i].host, family[i].people.size(), family[i].avg_sets, family[i].avg_area);
    }
    return 0;
}
