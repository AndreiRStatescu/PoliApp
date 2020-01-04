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
    char numE,prenumE;
    float nota_noua;
    int indice_materie;
    struct student v[200];
    int nrMat;
    printf("nr materi:\n");
    scanf("%d",&nrMat);
    char materii[31][51];
    for(i=0;i<nrMat;i++)
    {
        printf("materia %d:\n",i);
        scanf("%s",materii[i]);
    }
    inserare_nota(students,nrStud,materii,nrMat);
    //schimbare_nota(v,numE,prenumE,nota_noua,indice_materie);


    return 0;
}
