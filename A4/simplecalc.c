/*
Program to implement a simple calculator
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Feb 15 2020     Initial version
* Yiyi Yang 	Comp.Sci	Feb 16 2020	Change variable for input
* Yiyi Yang	Comp.Sci	Feb 18 2020	Debug
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){

if(argc != 4){
    printf("Error: usage is simplecalc <x> <op> <y> \n");
exit(1);
}

char op; int x,y;

sscanf(argv[1], "%d", &x);
sscanf(argv[2], "%c", &op);
sscanf(argv[3], "%d", &y);

if(op == '+' || op == '-' || op == '*' || op == '/'){
int sum, difference, product, quotient;
switch(op){
    case '+': sum = x + y;
    printf("%d\n", sum);
    break;
    case '-': difference = x-y;
    printf("%d\n", difference);
    break;
    case '*': product = x*y;
    printf("%d\n", product);
    break;
    case '/': quotient = x/y;
    printf("%d\n", quotient);
    break;
}
return 0;}
else{
printf("%c is not a valid operator\n", op);
    exit(2);
}


}