/*
implement a basic version of Caesar's cipher intepreter
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Feb 16 2020     Initial version
* Yiyi Yang	Comp.Sci	Feb 18 2020	Add print final array feature
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){{
    char letter[60];
    char c;
    int i;

    if (argc == 0 || argc == 1 ){
        printf("Error: usage is caesarcipher <offset>.\n");
        exit(1);
    }

    c = fgetc(stdin);
    int n = atoi(argv[1]);
    //scanf("%s", &garbage);
    //scanf("%s", &symbol);
    if ((c >= 'a' && c<= 'z')){
            c +=n;
        if (c < 'a') {
            c = c+26;}

        else if (c > 'z'){
            c = c-26;}}
    else if ((c >= 'A' && c<= 'Z')){
        c +=n;
        if(c < 'A'){
            c = c+26;}
        else if(c > 'Z'){
            c = c-26;
	    }
            }
    printf("%c", c);}
    return 0;
}

