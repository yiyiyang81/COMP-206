/*
implement a simple banking application
****************************************************************
* Author        Dept.           Date            Notes
****************************************************************
* Yiyi Yang     Comp.Sci        Mar 04 2020     Initial version
* Yiyi Yang     Comp.Sci        Mar 08 2020     Added scan command line argument
* Yiyi Yang     Comp.Sci        Mar 10 2020     First version finished
* Yiyi Yang     Comp.Sci        Mar 13 2020     Finished version
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addacc(char *accnum, char *name)
{
    FILE *myfile = fopen("bankdata.csv", "a+");
    fprintf(myfile,"AC,%s,%s\n", accnum, name);
    fclose(myfile);
}

void withdrawal(char *num, char *date, double amount)
{

    FILE *myfile = fopen("bankdata.csv", "a+");

    char buffer[100];
    char *filearg;
    char *filenum;
    char *filedate;
    char *balance;
    double add;
    double bal;
    add = 0.0;

    fgets(buffer, 100, myfile);

    while (!feof(myfile))
    {
        if (strstr(buffer, num) != NULL)
        {
            filearg = strtok(buffer, ",");

            if(strcmp(filearg,"TX")==0)
            {
                filenum = strtok(NULL, ",");

                filedate = strtok(NULL, ",");

                balance = strtok(NULL, "");

                bal = strtod(balance, NULL);

                add = bal + add;

            }
        }
        fgets(buffer, 100, myfile);
    }

    double test = add - amount;
    if (test < 0.0)
    {
        fprintf(stderr, "Error, account number %s has only %.2f\n", num, add);
        fclose(myfile);
        exit(60);
    }
    else
    {
        fprintf(myfile, "TX,%s,%s,-%.2f\n", num, date, amount);
        fclose(myfile);
    }
}

void deposit(char *num, char *date, double amount)
{
    FILE *myfile = fopen("bankdata.csv", "a+");
    fprintf(myfile, "TX,%s,%s,%.2f\n", num, date, amount);
    fclose(myfile);
}

void checkStringExists(char *accnum)
{
    FILE *myfile = fopen("bankdata.csv", "r");

    char buffer[100]; int i = 0;
    fgets(buffer, 100, myfile);

    while(!feof(myfile))
    {
        if(strstr(buffer, accnum)!=NULL) i++;
        fgets(buffer, 100, myfile);
    }
    if (i!=0)
    {
        fprintf(stderr,"Error, account number %s already exists\n", accnum);
        fclose(myfile);
        exit(50);
    }
    fclose(myfile);
}

void checkStringNotExists(char *accnum)
{
    FILE *myfile = fopen("bankdata.csv", "r");

    char buffer[100]; int i = 0;

    fgets(buffer, 100, myfile);

    while(!feof(myfile))
    {
        if(strstr(buffer, accnum)!=NULL) i++;
        fgets(buffer, 100, myfile);
    }
    if (i==0)
    {
        fprintf(stderr,"Error, account number %s does not exists\n", accnum);
        fclose(myfile);
        exit(50);
    }

    fclose(myfile);
}

void checkFileExists(void)
{
    FILE *myfile = fopen("bankdata.csv", "r");

    if (myfile == NULL)
    {
        fprintf(stderr, "Error, unable to locate the data file bankdata.csv\n");

        exit(100);
    }
    fclose(myfile);
}

int main(int argc, char *argv[])
{
    char *op;
    char *num;
    char *name;
    char *date;
    double amount;

    char buffer[1000];
    int bal;
    FILE *file;

    if (argc < 2)
    {
        fprintf(stderr, "Error, incorrect usage!\n-a ACCTNUM NAME\n-d ACCTNUM DATE AMOUNT\n-w ACCTNUM DATE AMOUNT\n");
        exit(1);
    }
    else if (strcmp(argv[1], "-a") == 0)
    {
        if (argc != 4)
        {
            fprintf(stderr, "Error, incorrect usage!\n-a ACCTNUM NAME\n");
            exit(1);
        }
        num = argv[2];
        name = argv[3];
        checkFileExists();
        checkStringExists(num);
        addacc(num, name);
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        if (argc != 5)
        {
            fprintf(stderr, "Error, incorrect usage!\n-d ACCTNUM DATE AMOUNT\n");
            exit(1);
        }
        num = argv[2];
        date = argv[3];
        amount = atof(argv[4]);
        checkFileExists();
        checkStringNotExists(num);
        deposit(num, date, amount);
    }
    else if (strcmp(argv[1], "-w") == 0)
    {
        if (argc != 5)
        {
            fprintf(stderr, "Error, incorrect usage!\n-w ACCTNUM DATE AMOUNT\n");
            exit(1);
        }
        num = argv[2];
        date = argv[3];
        amount = atof(argv[4]);
        checkFileExists();
        checkStringNotExists(num);
        withdrawal(num, date, amount);
    }
    else
    {
        fprintf(stderr, "Error, incorrect usage!\n-a ACCTNUM NAME\n-d ACCTNUM DATE AMOUNT\n-w ACCTNUM DATE AMOUNT\n");
        exit(1);
    }
    return 0;
}