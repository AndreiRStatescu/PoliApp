#include<stdio.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
};
struct sala
{
    char nume[11];
    char tip;///c,s, sau l
    int nrLoc;
};
void Read_Sali(struct sala sali[], int *nr, char finput[])
{
    FILE *fr = fopen(finput, "r");
    char line[101], *p;
    int k=0;
    while(fgets(line,100,fr))
    {
        p=strtok(line, ",");
        strcpy(sali[k].nume,p);
        p=strtok(NULL, ",");
        sali[k].nrLoc = atoi(p);
        p=strtok(NULL, ",");
        sali[k].tip = *p;
        p=strtok(NULL, ",");
        k++;
    }
    *nr=k;

}
