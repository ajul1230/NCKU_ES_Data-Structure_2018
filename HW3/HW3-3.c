#include<stdio.h>
#define SIZE 110  
#define INF 1000000
int map[SIZE][SIZE]; 
int len[SIZE];  	
int visit[SIZE];  
int n=0,m=0;
int A,B;  
int dijkstra(int from, int to)
{	
    int i;  
    for(i = 1 ; i <= n ; i ++)
	{	
        visit[i] = 0;	 
        len[i] = INF;	
    }  
 	len[from] = 0; 
    int j;  
    for(i = 0 ; i < n ; ++i)
	{	
        int min = INF;   
        int pos;  
  		for(j = 1 ; j <= n ; ++j)
		  {	
            if(!visit[j] && min > len[j])
			{  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit[pos] = 1;  
        for(j = 1 ; j <= n ; ++j)
		{
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j])))
			{   
                len[j] = len[pos] + map[pos][j];		
            }  
        }  
    }  
    return len[to];
}
int max(int a,int b) 
{
	return a > b ? a : b;
}
int main () 
{  
 	int i,j;  
    scanf("%d",&m);
	for(i = 1 ; i <= SIZE-1 ; ++i)
	{
        for(j = 1 ; j <= SIZE-1 ; ++j)
		{  
            map[i][j] = INF;  
			map[j][i] = INF;
			if (i == j) map[i][j] = 0;
        }  
    }  
	int a,b,c;	
    for(i = 1 ; i <= m ; ++i)
	{  
        scanf("%d%d%d",&a,&c,&b);  
        map[a][b] = map[b][a] = c;  
		n = max(n, a);	
		n = max(n, b);	
    }  
	scanf("%d%d",&A,&B);
    if(A==B)
    printf("0\n");
	else
	{
	int ans = dijkstra(A,B); 
	if(ans == INF)
	{
    	printf("404\n");
	}
	else
   		printf("%d\n",ans);
	}
 	return 0;  
} 
 


