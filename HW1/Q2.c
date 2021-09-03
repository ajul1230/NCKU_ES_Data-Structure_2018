#include <stdio.h>

int main()
{
	int cases;
	int length;
	int arr[100000];
	int i,input;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&length);
		for(i=0;i<100000;++i)
			arr[i]=0;
		for(i=0;i<length;++i){
			scanf("%d",&input);
			++arr[input];
		}
		for(i=0;i<=1000000;++i)
			if(arr[i]==1)
				break;
		printf("%d\n",i);
	}
 }
