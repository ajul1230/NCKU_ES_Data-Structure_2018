
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>
#define MAX_LENGTH 78763
clock_t start,finish;

static char ans[MAX_LENGTH];
static char data[MAX_LENGTH];

bool firstguess=0;
int cp=0;
int lcp;
int AN=0,BN=0;
char finalArr[MAX_LENGTH];

typedef struct NODE{
    char value[3];
    struct NODE *XX;//00,XX
    struct NODE *XO;//01,XO
    struct NODE *OX;//10,OX
    struct NODE *OO;//02,OO
}NODE;

NODE *rootPointer;

NODE* newNODE(char *v){
    NODE* dot=(NODE*)malloc(sizeof(NODE));
    strcpy(dot -> value,v);
    dot->XX =NULL;//00
    dot->XO =NULL;//01
    dot->OX =NULL;//10
    dot->OO =NULL;//02

    return(dot);
}


void read(char *fclue){
    int i=0;
    int j=0;
    char Astring[78763]= " ";
    char Bstring[78763]= " ";
    while(1){
        if(fclue[i]=='A'){
            i++;
            break;
        }
        else{
            Astring[i]=fclue[i];
        }
        i++;
    }
    AN=atoi(Astring);
    while(1){
        if(fclue[i]=='B'){
            break;
        }
        else{
            Bstring[j]=fclue[i];
        }
        i++;
        j++;
    }
    BN=atoi(Bstring);
}

void TwoBitCheck(){
    int TA=0;
    int TB=0;
    

    if(data[cp+1]==ans[cp+1]){
        TA++;
    }
    else if(data[cp]==ans[cp]){

        TA++;
    }
    else if(data[cp]==ans[cp+1])
    {
        TB++;
        if(data[cp+1]==ans[cp]){
        TB++;
        }
        if(data[cp+1]==ans[cp+1]){
            TB--;
        }
    }
    else if(data[cp+1]==ans[cp]){
        TB++;
        if(data[cp]==ans[cp+1]){
            TB++;
        }
        
        if(data[cp]==ans[cp]){
            TB--;
        }
    }
   
    AN=TA;
    BN=TB;
    if(data[cp]==ans[cp]&&data[cp+1]==ans[cp+1]){
        AN=2;
        BN=0;
    }
}

char *check(char data[MAX_LENGTH], char answer[MAX_LENGTH]) {
    static char clue[12];
    char temp_A[5],temp_B[5];
    int i;
    int A = 0;
    int ans_appear_times[10] = {0, 0, 0, 0, 0, 
                              0, 0, 0, 0, 0};
    int data_appear_times[10] = {0, 0, 0, 0, 0, 
                               0, 0, 0, 0, 0};

    for(i=0; i<MAX_LENGTH; i++) {
        if(data[i] == answer[i]) {
            A++;
        } 
        else {
            ans_appear_times[answer[i]-'0']++;
            data_appear_times[data[i]-'0']++;
        }  
    }
  
    int B = 0;
    for(i=0; i<10; i++) {
        if(data_appear_times[i] >= ans_appear_times[i]) {
            B += ans_appear_times[i];
        } 
        else {
            B += data_appear_times[i];
        }
    }
    if(A==MAX_LENGTH && B==0)	{
  	    return "AC";
    }
    sprintf(temp_A,"%d",A);  sprintf(temp_B,"%d",B);
    strcat(temp_A,"A"); strcat(temp_B,"B"); strcat(temp_A,temp_B);  strcpy(clue,temp_A);
    return clue;
} 

void Travel(NODE *root){
    printf("root: %s\n",root->value);
    //printf("value[0]:%c,value[1]:%c\n",root->value[0],root->value[1]);
    //printf("data[cp+1]:%c,data[cp]:%c\n",data[cp+1],data[cp]);
    //printf("ans[cp+1]:%c,ans[cp]:%c\n",ans[cp+1],ans[cp]);

    if(AN!=2){
        if((AN==0)&&(BN)==0){
            //printf("XX\n");
            data[cp+1]=root->XX->value[0];
            data[cp]=root->XX->value[1];
            root=root->XX;
        }else if((AN==0)&&(BN==1)){
            //printf("XO\n");
            data[cp+1]=root->XO->value[0];
            data[cp]=root->XO->value[1];
            root=root->XO;
        }else if((AN==1)&&(BN==0)){
            //printf("OX\n");
            data[cp+1]=root->OX->value[0];
            data[cp]=root->OX->value[1];
            root=root->OX;
        }else if((AN==0)&&(BN==2)){
            //printf("OO\n");
            data[cp+1]=root->OO->value[0];
            data[cp]=root->OO->value[1];
            root=root->OO;
        }
        //printf("data[cp]:%c%c\n",data[cp+1],data[cp]);
        TwoBitCheck();
        //printf("AN:%d,BN:%d\n",AN,BN);
        Travel(root);
    } 

}

char *guess(char *clue){
   

    NODE *root=newNODE("01");

    root->XX =newNODE("23");

    root->XX->XX =newNODE("45");

    root->XX->XX->XX =newNODE("67");
    root->XX->XX->XX->OO =newNODE("76");

    root->XX->XX->XX->XX =newNODE("89");
    root->XX->XX->XX->XX->OX =newNODE("88");
    root->XX->XX->XX->XX->OX->XX =newNODE("99");
    root->XX->XX->XX->XX->OO =newNODE("98");

    root->XX->XX->XX->XO =newNODE("78");
    root->XX->XX->XX->XO->XX =newNODE("96");
    root->XX->XX->XX->XO->XO =newNODE("86");
    root->XX->XX->XX->XO->OX =newNODE("79");


    root->XX->XX->XX->OX =newNODE("66");
    root->XX->XX->XX->OX->XX =newNODE("77");
    root->XX->XX->XX->OX->XX->OX =newNODE("87");
    root->XX->XX->XX->OX->XX->OX->OX =newNODE("97");
    root->XX->XX->XX->OX->OX =newNODE("68");
    root->XX->XX->XX->OX->OX->OX =newNODE("69");

    root->XX->XX->XO =newNODE("56");

    root->XX->XX->XO->XX =newNODE("74");
    root->XX->XX->XO->XX->OX =newNODE("84");
    root->XX->XX->XO->XX->OX->OX =newNODE("94");

    root->XX->XX->XO->XO =newNODE("64");

    root->XX->XX->XO->OX =newNODE("57");
    root->XX->XX->XO->OX->OX =newNODE("58");
    root->XX->XX->XO->OX->OX->OX =newNODE("59");

    root->XX->XX->OX =newNODE("44");

    root->XX->XX->OX->XX =newNODE("55");
    root->XX->XX->OX->XX->OX =newNODE("65");
    root->XX->XX->OX->XX->OX->OX =newNODE("75");
    root->XX->XX->OX->XX->OX->OX->OX =newNODE("85");
    root->XX->XX->OX->XX->OX->OX->OX->OX =newNODE("95");

    root->XX->XX->OX->OX =newNODE("46");
    root->XX->XX->OX->OX->OX =newNODE("47");
    root->XX->XX->OX->OX->OX->OX =newNODE("48");
    root->XX->XX->OX->OX->OX->OX->OX =newNODE("49");

    root->XX->XX->OO =newNODE("54");

    root->XX->XO =newNODE("34");

    root->XX->XO->XX =newNODE("52");
    root->XX->XO->XX->OX =newNODE("62");
    root->XX->XO->XX->OX->OX =newNODE("72");
    root->XX->XO->XX->OX->OX->OX =newNODE("82"); 
    root->XX->XO->XX->OX->OX->OX->OX =newNODE("92");

    root->XX->XO->XO =newNODE("42");

    root->XX->XO->OX =newNODE("35");
    root->XX->XO->OX->OX =newNODE("36");
    root->XX->XO->OX->OX->OX =newNODE("37");
    root->XX->XO->OX->OX->OX->OX =newNODE("38");
    root->XX->XO->OX->OX->OX->OX->OX =newNODE("39");

    root->XX->OX =newNODE("22");

    root->XX->OX->XX =newNODE("33");
    root->XX->OX->XX->OX =newNODE("43");
    root->XX->OX->XX->OX->OX =newNODE("53");
    root->XX->OX->XX->OX->OX->OX =newNODE("63");
    root->XX->OX->XX->OX->OX->OX->OX =newNODE("73");
    root->XX->OX->XX->OX->OX->OX->OX->OX =newNODE("83");
    root->XX->OX->XX->OX->OX->OX->OX->OX->OX =newNODE("93");

    root->XX->OX->OX =newNODE("23");
    root->XX->OX->OX->OX =newNODE("24");
    root->XX->OX->OX->OX->OX =newNODE("25");
    root->XX->OX->OX->OX->OX->OX =newNODE("26");
    root->XX->OX->OX->OX->OX->OX->OX =newNODE("27");
    root->XX->OX->OX->OX->OX->OX->OX->OX =newNODE("28");
    root->XX->OX->OX->OX->OX->OX->OX->OX->OX =newNODE("29");

    root->XX->OO =newNODE("32");

    root->XO =newNODE("20");
    root->XO->XX =newNODE("13");
    root->XO->XX->OX =newNODE("14");
    root->XO->XX->OX->OX =newNODE("15");
    root->XO->XX->OX->OX->OX =newNODE("16");
    root->XO->XX->OX->OX->OX->OX =newNODE("17");
    root->XO->XX->OX->OX->OX->OX->OX =newNODE("18");
    root->XO->XX->OX->OX->OX->OX->OX->OX =newNODE("19");

    root->XO->XO =newNODE("12");

    root->XO->OX =newNODE("30");
    root->XO->OX->OX =newNODE("40");
    root->XO->OX->OX->OX =newNODE("50");
    root->XO->OX->OX->OX->OX =newNODE("60");
    root->XO->OX->OX->OX->OX->OX =newNODE("70");
    root->XO->OX->OX->OX->OX->OX->OX =newNODE("80");
    root->XO->OX->OX->OX->OX->OX->OX->OX =newNODE("90");

    root->OX =newNODE("02");

    root->OX->XX =newNODE("11");
    root->OX->XO =newNODE("21");
    root->OX->XX->OX =newNODE("31");
    root->OX->XX->OX->OX =newNODE("41");
    root->OX->XX->OX->OX->OX =newNODE("51");
    root->OX->XX->OX->OX->OX->OX =newNODE("61");
    root->OX->XX->OX->OX->OX->OX->OX =newNODE("71");
    root->OX->XX->OX->OX->OX->OX->OX->OX =newNODE("81");
    root->OX->XX->OX->OX->OX->OX->OX->OX->OX =newNODE("91");

    root->OX->OX =newNODE("00");
    root->OX->OX->OX =newNODE("03");
    root->OX->OX->OX->OX =newNODE("04");
    root->OX->OX->OX->OX->OX =newNODE("05");
    root->OX->OX->OX->OX->OX->OX =newNODE("06");
    root->OX->OX->OX->OX->OX->OX->OX =newNODE("07");
    root->OX->OX->OX->OX->OX->OX->OX->OX =newNODE("08");
    root->OX->OX->OX->OX->OX->OX->OX->OX->OX =newNODE("09");
//
    root->OO =newNODE("10");

    if(firstguess==0){
        for(int i=0;i<MAX_LENGTH;i++){
            data[i]='a';
        }
        read(clue);
        firstguess = 1;
    }
    else if(cp<=78762){
            printf("cp:%d\n",cp);
            data[cp+1]=root->value[0];
            data[cp]=root->value[1];
            read(clue);
            TwoBitCheck();
            // printf("value[0]:%c,value[1]:%c\n",root->value[0],root->value[1]);
            // printf("data[cp+1]:%c,data[cp]:%c\n",data[cp+1],data[cp]);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>ans:%c%c\n",ans[cp+1],ans[cp]);
            // char stringstop[100];
            // scanf("%s",stringstop);
            
            // if((root->value[0]==1)&&(root->value[1]==0)){
            //     if(data[cp]==1){
            //     AN++;
            //     }else if(data[cp+1]==0){
            //         AN++;
            //     }else if(data[cp]==0){
            //         BN++;
            //         if(data[cp]==1){
            //             AN=1;
            //             BN=0;            
            //         }
            //     }else if(data[cp+1]==1){
            //         BN++;
            //         if(data[cp]==0){
            //             AN=1;
            //             BN=0;
            //         }
            //     }
            // }


            Travel(root);
            finalArr[cp]=data[cp];
            finalArr[cp+1]=data[cp+1];
            // printf("ans[%d]:%c\n",cp,ans[cp]);
            // printf("ans[%d]:%c\n",cp+1,ans[cp+1]);
            // printf("data[%d]:%c\n",cp,data[cp]);
            // printf("data[%d]:%c\n",cp+1,data[cp+1]);
            //finalArr[cp]=data[cp];
            //finalArr[cp+1]=data[cp+1];
            data[cp]='a';
            data[cp+1]='a';
            cp=cp+2;
    }else{
        // printf("finalArr[78759]:%c\n",finalArr[78759]);
        // printf("finalArr[78760]:%c\n",finalArr[78760]);
        // printf("finalArr[78761]:%c\n",finalArr[78761]);
        // printf("finalArr[78762]:%c\n",finalArr[78762]);
        // printf("ans[78759]:%c\n",ans[78759]);
        // printf("ans[78760]:%c\n",ans[78760]);
        // printf("ans[78761]:%c\n",ans[78761]);
        // printf("ans[78762]:%c\n",ans[78762]);
        // for(int i=0;i<10;i++){
        //     data[78762]=i+'0';
        //     check(data,ans);
        //     read(clue);
        //     if(AN==1)
        //         finalArr[78762]=i;
        //         break;
        // }
        for(int i=0;i<MAX_LENGTH;i++){
            data[i]=finalArr[i];
        }
    }
    return data;
}

int main(int argc, char *argv[]) {

//My Tree
    
//

    char get_back[MAX_LENGTH]="0A0B";   //initial input to guess function
    srand(time(NULL));
    struct timeval tval_before, tval_after, tval_result;

    int i;
    for(i=0; i<MAX_LENGTH; i++) {
        ans[i] = rand()%10+'0';
    }
    //time start
    gettimeofday(&tval_before, NULL);
    while(1){
        //get_back is mean that the result of your guess
        strcpy(get_back,check(guess(get_back), ans));	
        // your guessed right!!! Congratulation !!!
        if(strcmp(get_back,"AC")==0){
            printf("well done !\n");
            break;
        }
  	    gettimeofday(&tval_after, NULL);
  	    long t = (tval_after.tv_sec*1e6 + tval_after.tv_usec) - (tval_before.tv_sec*1e6 + tval_before.tv_usec);
  	    // convert to we can read
        const int n = snprintf(NULL, 0, "%lu", t);
        assert(n > 0);
        char buf[n+1];
        int c = snprintf(buf, n+1, "%lu", t);
        assert(buf[n] == '\0');
        assert(c == n);
        //print time
        int length = strlen(buf);
        if(length>6) {
            for(int i=0; i<length-6;i++){
                printf("%c",buf[i]);
            }
            printf(",");
            for(int i=length-6; i<length;i++) {
                printf("%c",buf[i]);
            }
            printf("\n"); 
        }
    }
    return 0;
}
