#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct sali
  { char numes[20] , tip_sala[20] ;
  int nr_locuri[20];
  };

  void Read_Sali(struct sali sala[] , int *nrs,char fscanS[])
  {FILE *f;
  f = fopen(fscanS, "r");
   char cladire[30],*p;
   int n=0;
   while(fgets(cladire,30,f))
     {  p=strtok(cladire, ",");
        strcpy(sala[n].numes,p);
        p=strtok(NULL, ",");
        strcpy(sala[n].tip_sala,p);
        p=strtok(NULL, ",");
        strcpy(sala[n].nr_locuri,p);
        p=strtok(NULL, ",");

        char c[4]; //partea de aici nu stiu exact cum ar trebui sa fie
        strcpy(c,p);
        n++;
    }
    *nrs=n;}//sfarsit si inceput

   struct materi
  { char numeM[20],numeP[20] , prenumeP[20] ;
  int nr_profesori[20],anStudi[];
  };
  void Read_Materi(struct materi materie[] , int *nrm,char fscanM[])
  {FILE *fi;
  fi = fopen(fscanM, "r");
   char programa[30],*l;
   int m=0;
   while(fgets(programa,30,fi))
    {
        l=strtok(programa, ",");
        strcpy(materie[m].numeM,l);
        l=strtok(NULL, ",");
        strcpy(materie[m].anStudi,l);
        l=strtok(NULL, ",");
        strcpy(materie[m].nr_profesori,l);
        if(strtok(NULL," ")==1)
        l=strtok(NULL, " ");
        strcpy(materie[m].numeP,l);
        l=strtok(NULL, ","); //mai trebuia cratima
        strcpy(materie[m].prenumeP,l);
        l=strtok(NULL, ",;");

        char a[6];
        strcpy(a,l);
        m++;
    }
    *nrm=m;
  }
