#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct sali
  { char numes[20] , tip_sala[20] ;
  int nr_locuri;
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

       char c[4];
        strcpy(c,p);
        sala[n].nr_locuri= atoi(c);
        p=strtok(NULL, ",");
        n++;
    }
    *nrs=n;}//sfarsit si inceput

   struct materi
  { char numeM[20],numeP[20][31] , prenumeP[20][31] ;
  int nr_profesori,anStudi;
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
        char j[20];
        strcpy(j,l);
        materie[m].nr_profesori = atoi(j);
        int i;
        for (i=0;i<materie[m].nr_profesori;i++)
        {
        l=strtok(NULL, " ");
        strcpy(materie[m].numeP[i][],l);
        l=strtok(NULL, ",");
        strcpy(materie[m].prenumeP[i][],l);
        l=strtok(NULL, ",;");
        }

        m++;
    }
    *nrm=m;
  }

  struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota[31];
};

void inserare_note(struct student stud[], int n,char materii[][31], int m)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("Nota lui %s %s la %s este: ", stud[i].nume, stud[i].prenume, materii[j]);
			scanf("%f", &stud[i].nota[j]);
		}
}
void schimbare_nota(struct student stud[], int n,char materii[][31], int m)
{
    int i,j;
    char numE[31],prenumE[31],mat[31];
    float nota_noua;
    printf("Dati numele dorit: ");
    fgets(numE,30,stdin);
    numE[strlen(numE)-1]='\0';
    printf("Dati prenume dorit: ");
    fgets(prenumE,30,stdin);
    prenumE[strlen(prenumE)-1]='\0';
    printf("Dati materia dorita: ");
    fgets(mat,30,stdin);
    mat[strlen(mat)-1]='\0';
    printf("Dati nota noua: ");
    scanf("%f",&nota_noua);
    for(i=0;i<n;i++)
        if(strcmp(numE,stud[i].nume)==0 && (strcmp(prenumE,stud[i].prenume)==0))
            for(j=0;j<m;j++)
                if(strcmp(materii[j],mat)==0)
                    stud[i].nota[j]=nota_noua;
}
