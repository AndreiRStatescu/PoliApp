#include<stdio.h>
#include<stdlib.h>

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


int login(char user[],char parola[],struct user v[], char tip[], int n)
{
    int i;
    for(i=0;i<n;i++)
    if(strcmp(user,v[i].username)==0 && strcmp(parola,v[i].password)==0 && strcmp(tip,v[i].type)==0)
        return i; //pozitia sa din vector
    return -1;//daca nu apare in vector
}
void cererePlata(char nume[],char prenume[])
{
    float suma;
    printf("Introduceti suma dorita: ");
    scanf("%f",&suma);
    FILE *f;
    char w[30],r[15],i[15];
    char rand[100]="";

    f=fopen("ToDoList.txt","a");
    int real,imaginar;
    real=suma;
    imaginar=(suma*100) - (real*100);
    itoa(real,r,10);
    itoa(imaginar,i,10);
    strcpy(w,r);
    strcat(w,".");
    strcat(w,i);


    strcat(rand,nume);
    strcat(rand," ");
    strcat(rand, prenume);
    strcat(rand," doreste sa achite ");
    strcat(rand,w);
    strcat(rand," lei");
    fprintf(f,"%s",rand);
    fprintf(f,"\n");
    fclose(f);
}

void stergereLista(int rand)
{
    FILE *f;
    f=fopen("ToDoList.txt","r+");
    char linie[101],m[50][101];
    int n=0,i;
    while(fgets(linie,100,f))
    {
        strcpy(m[n++],linie);
        m[n-1][strlen(m[n-1])-1]='\0';
    }
    fclose(f);
      f=fopen("ToDoList.txt","w");
    for(i=rand-1; i<n; i++)
    {
        strcpy(m[i],m[i+1]);
    }
    n--;
    for(i=0; i<n; i++)
        fprintf(f,"%s\n",m[i]);
}

void plata(struct student students[],int n)
{
    int i;
    char nume[31],prenume[31];
    float suma;
    printf("Nume: ");scanf("%s",nume);
    printf("Prenume: ");scanf("%s",prenume);
    printf("Suma: ");scanf("%f",&suma);
    for(i=0; i<n; i++)
    {
        if(stricmp(nume,students[i].nume)==0 && stricmp(prenume,students[i].prenume)==0)
            students[i].taxa=students[i].taxa-suma;
    }
}

void updateuser(struct user dates[],int n)
{
    FILE *f;
    int i;
    f=fopen("UsersData.txt","w+");
    for(i=0; i<n; i++)
    {
        fprintf(f,"%s ",dates[i].username);
        fprintf(f,"%s ",dates[i].password);
        fprintf(f,"%s ",dates[i].type);
        fprintf(f,"%s ",dates[i].nume);
        fprintf(f,"%s ",dates[i].prenume);
        fprintf(f,"\n");

    }

}
void updateStud(struct student v[], int nrStud,int nrMaterii)
{

    FILE *f;
    int i,j;

    f=fopen("StudentsData.txt","w+");
    for(i=0;i<nrStud;i++)
    {
        printf(f,"%s ",v[i].nume);
        printf(f,"%s ",v[i].prenume);
        printf(f,"%s ",v[i].sectie);
        printf(f,"%d ",v[i].an);
        printf(f,"%.2f ",v[i].taxa);
        for(j=0;j<nrMaterii;j++)
            printf(f,"%.2f",v[i].nota[j]);
        printf(f,"\n");

    }

}
