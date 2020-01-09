#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cosmin.h"
#include "dani.h"
#include "kristi.h"
#include "tania.h"
#include "victor.h"

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
}students[301];

int main()
{

    int i, nrStud;

    Read_Students(students,&nrStud,"InputStudents.csv");

    for(i=0;i<nrStud;i++)
    {
        printf("%s, %s, %d, %s\n",students[i].nume,students[i].prenume,students[i].an,students[i].sectie);
    }
    char nume[30],prenume[30],v[50];
    int n=2;
    scanf("%s",v);
    scanf("%s",nume);
    scanf("%s",prenume);
    eliminare(n,v,nume,prenume);

    return 0;
}
