/* helper functions for the main program
read the data file and parse each line to obtain variables
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Apr 10 2020     Initialization
* Yiyi Yang     Comp.Sci        Apr 11 2020     Implement parse
* Yiyi Yang     Comp.Sci        Apr 13 2020     Fix minor bugs
*/

#include <stdio.h>

void parse(char line[], int *coef, int *expo){
	sscanf(line, "%d %d", coef, expo);
}

int powi(int a, int b){
	int value = 1,i=0 ;
	while(i !=b){
	value = value*a;
	i++;}
	return value;
}

