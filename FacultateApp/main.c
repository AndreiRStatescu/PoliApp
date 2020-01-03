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

/*int main()
{

    int i, nrStud;

    Read_Students(students,&nrStud,"students_input.csv");

    for(i=0;i<nrStud;i++)
    {
        printf("%s, %s, %d, %s\n",students[i].nume,students[i].prenume,students[i].an,students[i].sectie);
    }

    return 0;
}*/



  int main()
{

    int i, nrStud;

    Read_Students(students,&nrStud,"students_input.csv");

    for(i=0;i<nrStud;i++)
    {
        printf("%s, %s, %d, %s\n",students[i].nume,students[i].prenume,students[i].an,students[i].sectie);
    }
    char numE,prenumE;
    float nota_noua;
    int indice_materie;
    struct student v[200];
    int n,m;
    /*printf(" %d n studenti=",n);scanf("%d",&n);
    printf(" %d m materi=",m);scanf("%d",&m);*/
    char materii[31][51];
    inserare_nota(v,n,materii,m);
    schimbare_nota(v,numE,prenumE,nota_noua,indice_materie);


    return 0;
}
