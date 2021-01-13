/*
.h file for poly.c
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Apr 10 2020     Initialization
* Yiyi Yang     Comp.Sci        Apr 11 2020     Added function names
* Yiyi Yang     Comp.Sci        Apr 13 2020     Commenting
*/

#ifndef POLY_H
#define POLY_H

struct PolyTerm
{
    int coeff;
    int expo;
    struct PolyTerm *next;
};

extern struct PolyTerm *head;

int addPolyTerm(int coe, int exp);
//function that accept two integer arguments and assimilates the term into the existing polynomial
//returns an integer as its return value, 0 indicates success and -1 indicates failure

void displayPolynomial();
//display the polynomial expression
//accpets no arguments and has no return

int evaluatePolynomial(int x);
//traverses the linked list, getting the values and use powi function to perform compuations
//accepts an iteger value for x and returns an integer that is obtained by evaluation

#endif //POLY_H