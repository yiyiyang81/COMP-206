/*
main program which requires passing a data file as its argument
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Apr 10 2020     Initialization
* Yiyi Yang     Comp.Sci        Apr 11 2020     added function read file
* Yiyi Yang     Comp.Sci        Apr 13 2020     Added section for parsing and display result, add comments
*/
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "poly.h"


int main(int argc, char *argv[]){
	char buffer[50];
	int c, e;
	FILE *myfile = fopen(argv[1], "r"); // read file

	if(myfile == NULL) //check if file was successfully read, exit if not
	{
		printf("File not found");
		return -1;
	}

	while(fgets(buffer, 49, myfile)) //read file line by line the file with fgets
	{
		parse(buffer, &c, &e);
		addPolyTerm(c, e);
	}


	displayPolynomial(); //first print polynomial


    for(int i=-2;i<3;i++) //calculate results from x=-2 to x=2
    {
		int result = evaluatePolynomial(i); //calculate y with function evaluatePolynomial
        printf("for x=%d, y=%d\n", i, result); // display results
    }


	fclose(myfile); //close file
}

