#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

struct node {
    int id;
    int virtue, talent, sum;
    int flag;
};

node stu[MAXN];
int n,l,h;

bool cmp(node x, node y){
    if(x.flag!=y.flag){
        return x.flag<y.flag;
    }
    if(x.sum!=y.sum){
        return x.sum>y.sum;
    }
    if(x.virtue!=y.virtue){
        return x.virtue>y.virtue;
    }
    return x.id<y.id;
}

int main() {
    scanf("%d%d%d", &n, &l, &h);
    int cnt=0;
    for (int i=0;i<n;i++) {
        int id,x,y;
        scanf("%d%d%d", &id, &x, &y);
        stu[i].id=id;
        stu[i].virtue=x;
        stu[i].talent=y;
        stu[i].sum=x+y;
        if(x>=l&&y>=l){
            cnt++;
            if(x>=h&&y>=h){
                stu[i].flag=1;
            }else if(x>=h&&y<h){
                stu[i].flag=2;
            }else if(x<h&&y<h&&x>=y){
                stu[i].flag=3;
            }else{
                stu[i].flag=4;
            }
        }else{
            stu[i].flag=5;
        }
    }
    sort(stu,stu+n,cmp);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%08d %d %d\n",stu[i].id,stu[i].virtue,stu[i].talent);
    }
    return 0;
}
