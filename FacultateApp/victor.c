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

void updateStud(struct student v[], int nrStud){
 FILE *f;
    int i;

     f=fopen("StudentsData.txt","w");
for(i=0;i<nrStud;i++)    {
        fprintf(f,"%s ",v[i].nume);
        fprintf(f,"%s ",v[i].prenume);
        fprintf(f,"%s ",v[i].sectie);
        fprintf(f,"%d ",v[i].an);
        fprintf(f,"%d ",v[i].taxa);
        fprintf(f,"%f",v[i].nota);
        fprintf(f,"\n");

    }}
int login(char user,char parola,struct user v[], char tip[])
{int n,i;
    for(i=0;i<n;i++)
    if(strcmp(user,v[i].username)==0 && strcmp(parola,v[i].password)==0 && strcmp(tip,v[i].type))
        return 1;
    else
        return 0;
}
void cerere(char nume[],char prenume[], float suma)
{
    FILE *f;
    char w[30];
    char rand[100]="";

    f=fopen("ToDoList.txt","a");
    itoa(suma,w,10);
    strcat(rand,nume);
    strcat(rand," ");
    strcat(rand, prenume);
    strcat(rand," doreste sa achite ");
    strcat(rand,w);
    strcat(rand," lei");
    fprintf(f,"%s",rand);
    fprintf(f,"\n");
}
void stergere(int rand)
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

void plata(char nume[],char prenume [],float suma,struct student students[],int n)
{
    int i;
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
    f=fopen("UsersData.txt","w");
    for(i=0; i<n; i++)
    {
        fprintf(f,"%s ",dates[i].nume);
        fprintf(f,"%s ",dates[i].prenume);
        fprintf(f,"%s ",dates[i].username);
        fprintf(f,"%s ",dates[i].password);
        fprintf(f,"%s ",dates[i].type);
        fprintf(f,"\n");

    }
}
