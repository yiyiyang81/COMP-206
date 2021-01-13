/* 
.h file for utils.c
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Apr 10 2020     Initialization
* Yiyi Yang     Comp.Sci        Apr 13 2020     Added ifndef statement
* Yiyi Yang     Comp.Sci        Apr 13 2020     Commenting
*/

#ifndef UTILS_H
#define UTILS_H

void parse(char line[], int *coef, int *expo);
//parse a line that was retrived using fgets and store the coefficient and exponent
//accepts a string and two integer pointers

int powi(int a, int b);
//calculate a raised to the power of exponent b
//accepts two integers, returns an ingeter

#endif //UTILS_H
