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

 struct sali
  { char numes[20] , tip_sala[20] ;
  int nr_locuri;
  }sala[20];

   struct materi
  { char numeM[20],numeP[20][31] , prenumeP[20][31] ;
  int nr_profesori,anStudi;
  }materie[20];

int main()
{  int i,m,n,nrs,nrm,nrStud,n2=0,m2=0;
    char numE,prenumE;
    float nota_noua;
    int indice_materie;
    struct student v[200];
    printf("%d Dati nr studenti=",n2);scanf("%d",&n2);
    printf("%d Dati nr materi=",m2);scanf("%d",&m2);
    char materii[31][51];
    inserare_note(v,n2,materie,m2);
    schimbare_nota(v,numE,prenumE,nota_noua,indice_materie);

     Read_Sali(sala,&nrs,"InputSali.csv");
   Read_Materi(materie,&nrm,"InputMaterii.csv");
   for(i=0;i<nrs;i++)
   {
       printf("%s, %d, %s\n",sala[i].numes,sala[i].tip_sala,sala[i].nr_locuri);
   }

    for(i=0;i<nrm;i++)
   {
       printf("%s, %d, %d,%s\n",materie[m].numeM,materie[m].anStudi,materie[m].nr_profesori,materie[m].numeP[i],materie[m].prenumeP[i]);
   }

    Read_Students(students,&nrStud,"InputStudents.csv");

    for(i=0;i<nrStud;i++)
    {
        printf("%s, %s, %d, %s\n",students[i].nume,students[i].prenume,students[i].an,students[i].sectie);
    }



    return 0;
}
