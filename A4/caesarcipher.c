/*
implement a basic version of Caesar's cipher intepreter
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Feb 16 2020     Initial version
* Yiyi Yang	Comp.Sci	Feb 18 2020	Add print final array feature
* Yiyi Yang	Comp.Sci	Feb 19 2020	Fix print multiple lines
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){
    char letter[60];
    char c;
    int i;

    if (argc == 0 || argc == 1 ){
        printf("Error: usage is caesarcipher <offset>\n");
        exit(1);
    }

    fgets(letter, 50, stdin);
    int n = atoi(argv[1]);
do{
    for (i=0; i<strlen(letter); i++){
        c = letter[i];
        if ((c >= 'a' && c<= 'z')){
            c = c-26+n;
		letter[i] = c;
            if (c < 'a') {
	    while (c < 'a'){
            c = c+26;}
	    letter[i] = c;
            }
            else if (c > 'z'){
            c = c-26;letter[i] = c;
            }
	}
        else if ((c >= 'A' && c<= 'Z')){
            c = c+n;letter[i] = c;
            if(c < 'A'){
            c = c+26;
		letter[i] = c;
            }
            else if(c > 'Z'){
            c = c-26;
	letter[i] = c;
	    }
            }
}

    for (i=0; i<strlen(letter);i++){
	//printf("%d", n);
        printf("%c", letter[i]);
    }}while(fgets(letter, 50, stdin) != NULL);
    return 0;
}