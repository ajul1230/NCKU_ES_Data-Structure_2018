#include<stdio.h> 
void reverse_words(char *str);
void reverse_chars(char *l, char *r);
void str_read(char[]);

int main()
{

   
   char str[100000] ;
   int cases,i;
   scanf("%d\n",&cases);
   for(i=0;i<cases;i++) { 
   str_read(str);

   reverse_words(str);
   
   printf("%s\n", str);
   } 
 
   

}


void reverse_words(char *str)
{
   char *start = str;
   char *end = str;

   
   while (*end != '\0') {
      ++end;
   }
   --end;

   reverse_chars(start, end);
   
   while (*start != '\0') {      
      for (;*start != '\0' && *start == ' '; start++) ;
    
      for (end=start; *end != '\0' && *end != ' '; end++) ;
      --end;

      reverse_chars(start, end); 
      start = ++end;
   }
}


void reverse_chars(char *l, char *r)
{
   char temp;
   while( l < r) {
      temp = *l;
      *l = *r;
      *r = temp;
      ++l;
      --r;
   }
}

void str_read(char str[]){
	int i =0;
	while(1){
		scanf("%c",&str[i]);
		if(str[i]=='\n')
		break;
		i++;
	}
	str[i]='\0';
}
