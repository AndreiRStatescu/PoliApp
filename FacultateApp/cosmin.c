#include<stdio.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
};

struct materi
  { char numeM[20],numeP[20][31] , prenumeP[20][31] ;
  int nr_profesori,anStudi,credite;
  };

  void Read_Materi(struct materi materie[] , int *nrm,char fscanM[])
  {FILE *fi;
  fi = fopen(fscanM, "r");
   char programa[101],*l;
   int m=0;
   while(fgets(programa,100,fi))
    {
        l=strtok(programa, ",");
        strcpy(materie[m].numeM,l);
        l=strtok(NULL, ",");

        char j[20];
        strcpy(j,l);
        materie[m].credite = atoi(j);
        l=strtok(NULL, ",");
        strcpy(j,l);
        materie[m].anStudi=atoi(j);
        l=strtok(NULL, ",");
        strcpy(j,l);
        materie[m].nr_profesori = atoi(j);

        int i;
        for (i=0;i<materie[m].nr_profesori;i++)
        {
        l=strtok(NULL, ",");
        strcpy(materie[m].numeP[i],l);
        l=strtok(NULL, ",");
        strcpy(materie[m].prenumeP[i],l);
       // l=strtok(NULL, ",");
        }
        m++;
    }
    *nrm=m;
  }
