#include<stdio.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota[31];
};
struct user
{
    char username[100],password[31],type[31],nume[31],prenume[31];
};

struct profesori
{
    char nume[100],materii[100][100],preferinte[100];
    int nrMaterii,oreMaterii[100];
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
        fscanf(fr,"%f",&students[k].taxa);
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
void eliminare(struct student v[], char nume[] , char prenume[],int nrStd, int nrMat)
{
    int i,k,j ;
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
        strcpy(v[j].prenume,v[j+1].prenume);
        strcpy(v[j].sectie,v[j+1].sectie);
        v[j].an=v[j+1].an;
        v[j].taxa=v[j+1].taxa;
        for(i=0;i<nrMat;i++)
            v[j].nota[i]=v[j+1].nota[i];
    }

}


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

void read_prof(struct profesori v[],int *nrP , char finput[])
{

    FILE *fi;
    fi = fopen(finput, "r");
    char linie[200],*p;
    int k=0,i,j;
    while(fgets(linie,200,fi))
    {
        p=strtok(linie,",");
        strcpy(v[k].nume,p);
        p=strtok(NULL,",");
        char aux[20];
        strcpy(aux,p);
        v[k].nrMaterii=atoi(aux);
        for(i=0;i<v[k].nrMaterii;i++)
        {

            p=strtok(NULL,",");
            strcpy(v[k].materii[i],p);


        }
        for(j=0;j<v[k].nrMaterii;j++)
        {
            p=strtok(NULL,",");
            strcpy(aux,p);
            v[k].oreMaterii[j]=atoi(aux);
        }


        p=strtok(NULL,",");
        strcpy(v[k].preferinte,p);
         k++;
    }
    *nrP=k;

}

struct materie
  {
    char numeM[20],numeP[20][31] , prenumeP[20][31] ;
    int nr_profesori,anStudi,credite;
  };

void eliberare(struct materie v[], char nume[], char prenume[],int an , int nrMaterii)
{

    FILE *f;
    char fname[]="ContractStudiu";
    strcat(fname,nume);
    strcat(fname,prenume);
    strcat(fname,".html");
    f=fopen(fname,"w+");
    fprintf(f,"<html>\n<body>\n<h1>Contract de Studiu</h1>\n");
    fprintf(f,"<h2>%s %s, anul %d</h2>\n",nume,prenume,an);
    fprintf(f,"<p>Materie,Credite:</p>\n");
    int i,scredite=0;
    for(i=0;i<nrMaterii;i++)
    {
        if(v[i].anStudi == an)
        {

            fprintf(f,"<p>%s : %d<p>\n",v[i].numeM , v[i].credite);
            scredite+=v[i].credite;
        }

    }
    fprintf(f,"<p>TOTAL CREDITE: %d</p>\n\n",scredite);
    fprintf(f,"</body>\n</html>\n");
}
