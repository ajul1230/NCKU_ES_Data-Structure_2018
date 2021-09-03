#include <stdio.h>
#include <string.h>

int main(void) 
{
	int s,i,q,len,j,k,oddlen,evenlen;
	char odd[1000];
	char even[1000];
	char in[1000];
	char out[1000];
	
	scanf("%d",&s);
	
	memset (out,'0',sizeof(char)*1000);
	memset (odd,'\0',sizeof(char)*1000);
	memset (even,'\0',sizeof(char)*1000);
	 
	for (i=1;i<=s;i++)  
	{
		memset (in,'\0',sizeof(char)*1000);
		scanf("%s",in);
		oddlen=strlen(odd);
		evenlen=strlen(even);
		if((i%2)==1)
		{
			strcat(odd,in);
			
		}else if((i%2)==0)
		{
			strcat(even,in);
		
		}
	}
 	
	for (q=0;q<strlen(odd);q++)
		out[q] = out[q] + odd[strlen(odd)-1-q]-48;
	for (q=0;q<strlen(even);q++)
		out[q] = out[q] + even[strlen(even)-1-q]-48;
		
	
	for (q=0;out[q]!='\0';q++)
	{
		if ((out[q])>57)
		{
			out[q] = out[q]-10;
			if (out[q+1]=='\0')
				out[q+1] = '1';
			else 
				out[q+1]++;
		}
	}
		
	j=999;
	while (out[j]=='0' && j>0)
		j--;
		
	while (j>=0)
	{
		printf("%c",out[j]);
		j--;	
	}
	
	return 0;
}

