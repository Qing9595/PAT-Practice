#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int fee[24];
//int month=1;
int n;

struct node {
    char name[20];
    int month;
    int dd, hh, mm;
    int status;
};


node record[MAXN];

bool cmp(node x,node y){
    if(strcmp(x.name,y.name)!=0){
        return strcmp(x.name,y.name)<0;
    }
    if(x.dd!=y.dd){
        return x.dd<y.dd;
    }
    if(x.hh!=y.hh){
        return x.hh<y.hh;
    }
    if(x.mm!=y.mm){
        return x.mm<y.mm;
    }
    return x.status<y.status;
}

int calc_fee(int t1, int t2) {
    /*
    int money = 0;
    int time = t1;
    while(time<t2){
        money+=fee[(time%1440)/60];
        time++;
    }
    return money;
    */
    int money = 0;
    int x1=t1%1440/60;
    int x2=t2%1440/60;
    if(t2-t1<=60 && x1/60==(x2-1)/60){
        return (t2-t1)*fee[t1%1440/60];
    }
    else{
        int time=t1;
        int xx1=t1/60, xx2=t2/60+1;
        int sp=xx2-xx1;
        for(int i=0;i<sp;i++){
            money+=fee[time%1440/60]*60;
            time+=60;
        }
        money-=(t1-(t1/60)*60)*fee[t1%1440/60];
        money-=((t2/60+1)*60-t2)*fee[t2%1440/60];
    }
    return money;
}

void printans(int start, int stop) {
    printf("%s %02d\n",record[start].name,record[start].month);
    int total = 0;
    for (int i=start;i<stop;) {
        if(record[i].status==0 && record[i+1].status==1) {
            int t1=record[i].dd*1440+record[i].hh*60+record[i].mm;
            int t2=record[i+1].dd*1440+record[i+1].hh*60+record[i+1].mm;
            int fee = calc_fee(t1,t2);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", record[i].dd,record[i].hh,record[i].mm,record[i+1].dd,record[i+1].hh,record[i+1].mm,t2-t1,fee/100.0d);
            total+=fee;
            i+=2;
        }
        else{
            i++;
        }
    }
    printf("Total amount: $%.2lf\n",total/100.0d);
}

int main() {
    for(int i=0;i<24;i++){
        scanf("%d",&fee[i]);
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char flag[10];
        scanf("%s %d:%d:%d:%d %s",&record[i].name,&record[i].month,&record[i].dd,&record[i].hh,&record[i].mm,&flag);
        if(strcmp(flag,"on-line")==0){
            record[i].status=0;
        }
        else{
            record[i].status=1;
        }
    }
    sort(record,record+n,cmp);
    /*
    for(int i=0;i<n;i++){
        cout<<record[i].name<<' '<<record[i].dd<<' '<<record[i].hh<<' '<<record[i].mm<<' '<<record[i].status<<endl;
    }
    */
    int needPrint = 0;
    char curName[20];
    int pos = 0;
    strcpy(curName, record[0].name);
    bool flag=0;

    for (int i=0;i<n;) {
        if (strcmp(curName,record[i].name)!=0 || i==n-1){

            if(needPrint==2){
                if(i!=n-1)
                    printans(pos,i-1);
                else{
                    printans(pos,i);
                    break;
                }
            }
            pos=i;
            needPrint=0;
            strcpy(curName,record[i].name);
            continue;
        }
        else{
            if(needPrint==0 && record[i].status==0 && i+1<n && strcmp(record[i+1].name,record[i].name)==0 && record[i+1].status==1)
                {needPrint=2;}
            /*
            else if(needPrint==1 && record[i].status==1 && flag==1)
                {needPrint=2;}
            else if(needPrint==1 && record[i].status==0)
                {needPrint=0;flag=0;}
            */
            i++;
        }
    }
    return 0;
}
