#include <bits/stdc++.h>
using namespace std;
#define MAXN 30005

struct node {
	char num[13];
	int location;
	int score;
};

node stu[MAXN];
int location_rank[101];
int location_num[101];
int location_score[101];

bool cmp(node x,node y){
	if(x.score!=y.score){
		return x.score>y.score;
	}
	return strcmp(x.num,y.num)<0;
}

void init(){
	for(int i=1;i<=100;i++){
		location_rank[i]=1;
		location_num[i]=1;
		location_score[i]=-1;
	}
}

int main() {
	init();
	int n;
	int total = 0;
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		int k;
		scanf("%d", &k);
		while (k--){
			scanf("%s%d",&stu[total].num, &stu[total].score);
			stu[total].location=i;
			total++;
		}
	}
	sort(stu,stu+total,cmp);
	printf("%d\n",total);

	int final_rank=1;
	printf("%s %d %d %d\n",stu[0].num,1,stu[0].location,1);

	location_num[stu[0].location]++;
	location_score[stu[0].location]=stu[0].score;
	for(int i=1;i<total;i++){
		printf("%s ",stu[i].num);
		if(stu[i].score!=stu[i-1].score){
			printf("%d ", i+1);
			final_rank=i+1;
		} else {
			printf("%d ", final_rank);
		}
		int loca=stu[i].location;
		printf("%d ", loca);
		if(stu[i].score!=location_score[loca]){
			printf("%d",location_num[loca]);
			location_rank[loca]=location_num[loca];
			location_num[loca]++;
			location_score[loca]=stu[i].score;
		}else{
			printf("%d",location_rank[loca]);
			location_num[loca]++;
		}
		printf("\n");
	}
	return 0;
}
