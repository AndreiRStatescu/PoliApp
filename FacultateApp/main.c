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

struct user
{
    char username[100],password[31],type[31],nume[31],prenume[31];
}users[301];

struct materie
  {
    char numeM[20],numeP[20][31] , prenumeP[20][31] ;
    int nr_profesori,anStudi,credite;
  }materii[301];

struct profesori
{
    char nume[100],materii[100][100],preferinte[100];
    int nrMaterii,oreMaterii[100];
}profi[301];

int main()
{
    int nrStud , nrUsers,i;
    int nrMat=3 ,nrProfi,an=1;
    GetStudents(students , &nrStud,nrMat,"StudentsData.txt" );
    Read_Materi(materii,&nrMat,"InputMaterii.txt");
    GetUsers(users,&nrUsers,"UsersData.txt");
    char nume[31], prenume[31], sectie[11];
    printf("dati un nume ");
    scanf("%s",nume);
    printf("dati un prenume ");
    scanf("%s",prenume);
    printf("dati sectia :");
    scanf("%s",sectie);
    transfer(students,nrStud,nume,prenume,sectie);

    eliminare(students,nume,prenume,nrStud,nrMat);

    nrStud--;
 for(i=0;i<nrStud;i++)
            printf("%s %s %s \n",students[i].nume,students[i].prenume,students[i].sectie );

    read_prof(profi,&nrProfi,"InputProfs.txt");

    for(i=0;i<nrProfi;i++)
        printf("%s \n" , profi[i].nume);


    GetUsers(users,&nrUsers,"UserData.txt");
    for(i=0;i<nrUsers;i++)
        printf("%s %s\n",users[i].username,users[i].type);


    eliberare(materii,"Daniel","Sergiu",1,nrMat);

    return 0;
}
