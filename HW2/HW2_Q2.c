#include <stdio.h>
#include <string.h>
int main(void)
{
	int m,i,j,k,l,y,loc,n;
	scanf("%d%*c",&m);
	char input[5000];
	char find[1000];
	char replace[500];
	//for (i=0;i<m;i++)
	//{
		memset (input,'\0',sizeof(char)*5000);
		memset (find,'\0',sizeof(char)*2000);
		memset (replace,'\0',sizeof(char)*2000);
		fgets(input,sizeof(input),stdin);//輸入原始字串
		fgets(find,sizeof(find),stdin);//輸入將被取代的字串+取代字串 
		fgets(replace,sizeof(replace),stdin);
		find[strlen(find)-1]='\0';//拔掉\n
		input[strlen(input)-1]='\0';
		replace[strlen(replace)-1]='\0';
//---------------------------------------------------------------------------------------------------------------------		
		/*if (find[0]==' ')//狀況:  XXXXX 
		{
			for (j=2;j<strlen(find);j++) //把find第二個之後的複製到replace 
				replace[j-2] = find[j];
			memset (find,'\0',sizeof(char)*100);//洗掉find 
			find[0]=' ';//find第一個為空格		
		}
		else //狀況:XX XXXX 
		{		
			for (j=0;j<strlen(find);j++)//找出空格，在第j格 
			{
				if (find[j]==' ')
					break;
			}
			l=strlen(find);//紀錄find目前長度，因為等等會變短 
			for (k=0;k<l;k++)//把find空格之後的複製到replace 
				{
					replace[k]=find[k+j+1];
					find[k+j+1]='\0';
				}
			find[j]='\0';//把' '改成'\0' 
		}*/ 
		for(m=0;m<strlen(input);m++)
            {
                if(input[m]>=65&&input[m]<=90)
                {
                    for(n=0;n<strlen(find);n++)
                        {
                            if(input[m]==find[n]-32)
                                 input[m]+=32;
                        }
                }

            }
//--------------------------------------------------------------------------------------------------------------------- 
		for (j=0;j<strlen(input);j++)
		{
			if (input[j]==find[0])
			{
				for (k=0;k<strlen(find);k++)
				{
					if (input[j+k]==find[k] && k!=(strlen(find)-1))
						continue;
					if (input[j+k]!=find[k])
						break;
					if (input[j+k]==find[k])
						input[j]='\n';
				}
			}	
		} 
//--------------------------------------------------------------------------------------------------------------------- 
 		for (j=0;j<(strlen(input));j++)
 		{
 			if (input[j]=='\n')
			{
				printf("%s",replace);
				j=(j+strlen(find)-1);
			}	
			else
				printf("%c",input[j]);
		}
		printf("\n"); 
//---------------------------------------------------------------------------------------------------------------------				
	//}//end for
	return 0;
}//end main    
