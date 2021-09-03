#include <stdio.h>

int main()
{
	double input;
	int arr[1000];
	int i,cases,num=0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lf",&input);
		if(input-(int)input==0)		
			arr[num++]=input;
	}
	printf("%d\n",num);
	for(i=0;i<num;++i)
		printf("%d\n",arr[i]);
	
 } 
