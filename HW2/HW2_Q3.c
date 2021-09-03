#include<stdio.h>
struct way{
	int start;
	int end;
};
int pass(int position,struct way passage[],int *player,int dragon[],int J,int *fail,int *victory,int L){
	if(*player>=L)return 0;
	if(*player>dragon[position]){
		(*player)+=dragon[position];
		(*victory)++;
	}
	else{
		(*fail)++;
		return 0;
	}
	int i,j=0,k[100];
	for(i=0;i<J;i++){
		if(position==passage[i].start){
			k[j]=passage[i].end;
			j++;}}
	for(i=0;i<j;i++){
		pass(k[i],passage,player,dragon,J,fail,victory,L);
		}
	}

int main(){
	int N,J,K,L;
	scanf("%d",&N);
	scanf("%d",&J);
	scanf("%d",&K);
	scanf("%d",&L);
	int dragon[N],position=0,i;
	int player=K,fail=0,victory=0;
	struct way passage[J];
	for(i=0;i<N;i++)scanf("%d",&dragon[i]);
	for(i=0;i<J;i++){
	scanf("%d",&passage[i].start);
	scanf("%d",&passage[i].end);
	}
	pass(0,passage,&player,dragon,J,&fail,&victory,L);
	printf("%d",fail);
	printf(" ");
	printf("%d",victory);
	printf(" ");
	printf("%d",player);
	}
	

