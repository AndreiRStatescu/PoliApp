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

struct profesor
{
    char nume[31], prenume[31], materii[5][31];
    int rol[31][3];///linia reprezinta materia, coloana: 0-Curs, 1-Seminar, 2-Laborator, daca rol[i]=1 atunci profesorul indeplineste rolul i
    int nrOre[5],nrMaterii;
    struct preferinta
    {
        int ora;
        char sala[11];
    }pref[5];
}profesors[101];

struct sala
{
    char nume[11];
    char tip;///c,s, sau l
    int nrLoc;
}sali[101];
struct materii
{
    char nume[31];
    int an, nrProfi;
    int profs[31];///retine doar indicii profesorilor
};

int main()
{

    int i, nrStud, nrSali;

    Read_Students(students,&nrStud,"InputStudents.csv");
    Read_Sali(sali, &nrSali,"InputSali.csv");

    for(i=0;i<nrStud;i++)
    {
        printf("%s, %s, %d, %s\n",students[i].nume,students[i].prenume,students[i].an,students[i].sectie);
    }
    printf("\n");
    for(i=0;i<nrSali;i++)
    {
        printf("%s, %d, %c\n",sali[i].nume,sali[i].nrLoc,sali[i].tip);
    }

    return 0;
}
