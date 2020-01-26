#include<stdio.h>
#include<string.h>
struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
};
void eliminare(struct student v[], char nume[] , char prenume[],int nrStd)
{
    int i,k,j ,x;
    for(i=0;i<nrStd;i++)
    {
        if(strcmp(v[i].nume,nume)==0 && strcmp(v[i].prenume,prenume)==0)
        {
            k=i;
            break;
        }
    }
    for(j=k;j<nrStd;j++)
    {
        strcpy(v[j].nume,v[j+1].nume);
    }
    for(x=k;x<nrStd;x++)
        strcpy(v[x].prenume,v[x+1].prenume);

}

//
void transfer(struct student students[], int nrStd , char nume[],char prenume[],char sectienoua[])
{
    int i,k;
    for(i=0;i<nrStd;i++)
    {
        if(strcmp(students[i].nume,nume)==0 && strcmp(students[i].prenume,prenume)==0)
        {
             strcpy(students[i].sectie,sectienoua);
        }
    }
}

//
struct profesori
{
    char nume[100],materii[100][100],preferinte[100];
    int nrMaterii,oreMaterii[100];
};
void read_prof(struct profesori v[],int *nrP , char finput[])
{

    FILE *fi;
  fi = fopen(finput, "r");
    char linie[200],*p;
    int k=0;
    while(fgets(linie,200,fi))
    {
        p=strtok(linie,",");
        strcpy(v[k].nume,p);
        p=strtok(NULL,",");
        strcpy(v[k].nrMaterii,p);
        char aux[20];
        strcpy(aux,p);
        v[k].nrMaterii=atoi(aux);
        for(int i=0;i<v[k].nrMaterii;i++)
        {

            p=strtok(NULL,",");
            strcpy(v[k].materii[i],p);


        }
        for(int j=0;j<v[k].nrMaterii;j++)
        {
            p=strtok(NULL,",");
            strcpy(v[k].oreMaterii[j],p);
        }

       
        p=strtok(NULL,",");
        strcpy(v[k].preferinte,p);
         k++;
    }
    *nrP=k;

}

//
struct materie
  {
    char numeM[20],numeP[20][31] , prenumeP[20][31] ;
    int nr_profesori,anStudi,credite;
  };
void functie (struct materie v[], char nume[], char prenume[],int an , int nrMaterii)
{

    FILE *f;
    f=fopen("ContractStudent.html","w");
    fprintf(f,"<html>\n<body>\n<h1>Contract de Studiu</h1>\n");
    fprintf(f,"%s %s, anul %d\n",nume,prenume,an);
    fprintf(f,"<p>Materie,Credite:</p>\n");
    int i;
    for(i=0;i<nrMaterii;i++)
    {
        fprintf(f,"<p>%s : %d<p>\n",v[i].numeM , v[i].credite);

    }

    fprintf(f,"</body>\n</html>\n");
}

//

struct user
{
    char username[100],password[31],type[31],nume[31],prenume[31];
};

void GetStudents(struct student students[],int *nrS,int nrMaterii, char finput[])
{
    FILE *fr = fopen(finput, "r");
    int k=0,i;

    while(fscanf(fr,"%s",students[k].nume) == 1)
    {
        fscanf(fr,"%s",students[k].prenume);
        fscanf(fr,"%s",students[k].sectie);
        fscanf(fr,"%d",&students[k].an);
        fscanf(fr,"%d",&students[k].taxa);
        for(i=0;i<nrMaterii;i++)
            fscanf(fr,"%f",&students[k].nota[i]);
        k++;
    }
    *nrS=k;
}
void GetUsers(struct user users[],int *nrU, char finput[])
{
    FILE *fr = fopen(finput, "r");
    int k=0,i;

    while(fscanf(fr,"%s",users[k].username) == 1)
    {
        fscanf(fr,"%s",users[k].password);
        fscanf(fr,"%s",users[k].type);
        fscanf(fr,"%s",users[k].nume);
        fscanf(fr,"%s",users[k].prenume);
        k++;
    }
    *nrU=k;
}