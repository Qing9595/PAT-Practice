#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000

struct node {
    int id;
    int grade[4];
};

node stu[MAXN];
char course[]={'A','C','M','E'};

set<int> ids;

int ranks[1000000][4]={0};
int now=0;

bool cmp(node x, node y){
    return x.grade[now]>y.grade[now];
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;i++) {
        int id,c,m,e,a;
        scanf("%d%d%d%d",&id,&c,&m,&e);
        ids.insert(id);
        a=(c+m+e);
        stu[i].id=id;
        stu[i].grade[0]=a;
        stu[i].grade[1]=c;
        stu[i].grade[2]=m;
        stu[i].grade[3]=e;
    }
    for(now=0;now<4;now++){
        sort(stu,stu+n,cmp);
        ranks[stu[0].id][now]=1;
        int k=1;
        for(int i=1;i<n;i++){
            if(stu[i].grade[now]!=stu[i-1].grade[now]){
                ranks[stu[i].id][now]=i+1;
            }else{
                ranks[stu[i].id][now]=ranks[stu[i-1].id][now];
            }
        }
    }
    while(m--){
        int p;
        scanf("%d",&p);
        if(ids.find(p)!=ids.end()){
            int k=0;
            for(int j=0;j<4;j++){
                if(ranks[p][j]<ranks[p][k]){
                    k=j;
                }
            }
            printf("%d %c\n",ranks[p][k],course[k]);
        }
        else{
            printf("N/A\n");
        }
    }
    return 0;
}
