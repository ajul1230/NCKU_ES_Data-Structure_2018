#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define len 1000



int i,j;
int eof_fuc(char word[]) {
    char ch;
    ch= getchar();
    if (ch==(EOF)) {
        return 1;
    }
    else
        ungetc(ch, stdin);
        return 0;
}


int eof() {
    char a = getchar();
    while (a == '\0' || a == '\n') {
        a = getchar();
    }

    if (a != -1) {
        ungetc(a, stdin);
        return 1;
    }
    return 0;
}


int seq(char a) {
    int i;
    if ((a >= '0' && a <= '9')) {
        return i=2*'z'+a;
    }
    else if (a >= 'a' && a <= 'z') {
        return i=a*2;
    }
    else if ((a >= 'A' && a <= 'Z')) {
        a= tolower(a);
        return i=a*2-1;
    }
    return 0;
}

int firstNumber(char a[], char b[]) {
	int i;
    for (i=0; ; i++) {
        if (seq(a[i])<seq(b[i])) {
            return 0;
        }
        else if (seq(a[i])>seq(b[i])) {
            return 1;
        }
        else if(i==strlen(a)-1) {
            return 0;
        }
        else if(i==strlen(b)-1) {
            return 1;
        }
    }
}

void resultFuc(char keyarr[len][len], int keyNumArr[len], int keyNum) {
    int keyNumMax= keyNumArr[0];
    int temp=0;
    int i;
    for (i=0; i<keyNum; i++) {
        if (keyNumArr[i]>keyNumMax) {
            temp=i;
            keyNumMax=keyNumArr[i];
        }
    }
    int maxNum=0;
    for (i=0; i<keyNum; i++) {
        if (keyNumArr[i]==keyNumMax) {
            maxNum++;
        }
    }
    if (maxNum==1) {
        printf("%s %d\n", keyarr[temp], keyNumArr[temp]);
    }

    else if (maxNum!=1) {
        for (i=0; i<maxNum; i++) {
            int temp=-1;
            for (j=0; j<keyNum; j++) {
                if (keyNumArr[j]==keyNumMax) {
                    if (temp==-1) {
                        temp=j;
                    }
                    else if (firstNumber(keyarr[temp], keyarr[j])==1) {
                        temp=j;

                    }
                }
            }
            printf("%s %d\n", keyarr[temp], keyNumArr[temp]);
            keyNumArr[temp]=0;
        }
    }
}

void getString(char get[]) {
    int length= 0;
    char a= getchar();
    for(i=0; i<len; i++) {
    	get[i]='\0';
	}
    while (((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) == 1) {
        get[length]= a;
        a= getchar();
        length++;
    }
}


int main() {
    int keyNum=0;
    char keyarr[len][len];

    while (1) {
        scanf("%s", keyarr[keyNum]);
        char ch;
        ch= getchar();
        if (keyarr[keyNum][0]=='-') {
            break;
        }
        keyNum++;
    }

    int keyNumArr[keyNum];
    for (i=0; i<keyNum; i++) {
        keyNumArr[i]=0;
    }

    while (eof()) {
        char get[len];
        getString(get);
        for (i=0; i<keyNum; i++) {
            if ((strcmp(get, keyarr[i]))==0) {
                keyNumArr[i]++;
            }
        }
    }
    resultFuc(keyarr, keyNumArr, keyNum);
}

