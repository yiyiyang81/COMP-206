/*

****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Apr 10 2020     Initialization
* Yiyi Yang     Comp.Sci        Apr 12 2020     Implementation of add PolyTerm and displayPolynomial
* Yiyi Yang     Comp.Sci        Apr 13 2020     Implementation of evaluatePolyTerm, commenting
* Yiyi Yang     Comp.Sci        Apr 13 2020     Add print new line for displayPolyTerm
* Yiyi Yang     Comp.Sci        Apr 14 2020     Finished debugging
*/
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

struct PolyTerm
{
    int coeff;
    int expo;
    struct PolyTerm *next;
};


struct PolyTerm *head = NULL;
int addPolyTerm(int coe, int exp){
    struct PolyTerm *new = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
    if(new == NULL) return -1; // check if new was created successfully, return -1 if not

    new->coeff = coe; //assign input values to new
    new->expo = exp;
    new->next =NULL;

    if(head == NULL) //check if head is empty
    {   
        head = new;  //make new become the head if is true
        return 0;
    }
    else
    {
        int ctr = 0;
        struct PolyTerm *tmp = head;
        struct PolyTerm *store = head; //temporary PolyTerm for storing the pointer

        while ( new->expo > tmp->expo) //compare the exponent of new with existing terms
        {
                if(tmp->next ==NULL)
                {
                    tmp->next = new;
                    return 0;
                }
                tmp = tmp->next; //stop when find the right position
                ctr ++;
        }

        if(new->expo == tmp->expo) //case when needs to add up the coefficient
        {
            tmp->coeff = tmp->coeff + new->coeff;
            return 0;
        }
        else if(new->expo < tmp->expo) //case when need to insert new term
        {
            if(tmp->expo == head->expo) //when needs to replace head
            {
                new->next = head;
                head = new;
                return 0;
            }
            else
            {
                for (int i = 0; i < ctr-1; i++)
                {
                    store = store->next;
                    i++;
                }
                store->next = new;
                new->next = tmp;
                return 0;
            }
        }
    }

    return 0; //return 0 if successed
}


void displayPolynomial()
{
    printf("%dx%d", head->coeff, head->expo); //print the head first

    struct PolyTerm *tmp = head->next; //iterate through linked list from the second element

    while (tmp !=NULL) //whlil not th end of the list
    {
        if(tmp->coeff<0) //check if coefficient is negative and print plus sign accordingly
        {
            printf("%dx%d", tmp->coeff, tmp->expo); 
        }
        else
        {
            printf("+%dx%d", tmp->coeff, tmp->expo);

        }
        
        tmp = tmp->next;
    }
    printf("\n");

}



int evaluatePolynomial(int x)
{
    struct PolyTerm *tmp = head; // let tmp point to head
    int result = 0;

    while(tmp != NULL) //while not the end of the link list
    {
        result += tmp->coeff * powi(x, tmp->expo); //add up result of each term
        tmp = tmp->next; //move to the next term
    }

    return result; //return result
    
}
