#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
};

void Read_Students(struct student students[], int *nr, char finput[])
{
    FILE *fr = fopen(finput, "r");
    char line[101], *p;
    int k=0;
    while(fgets(line,100,fr))
    {
        p=strtok(line, ",");
        strcpy(students[k].nume,p);
        p=strtok(NULL, ",");
        strcpy(students[k].prenume,p);
        p=strtok(NULL, ",");
        students[k].an = atoi(p);
        p=strtok(NULL, ",");
        strcpy(students[k].sectie,p);
        p=strtok(NULL, ",");
        char t[5];
        strcpy(t,p);
        students[k].taxa = atof(t);
        k++;
    }
    *nr=k;
}
