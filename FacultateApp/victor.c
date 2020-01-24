#include<stdio.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota[31];
};
struct date
{char username[30];
char password[30];

};

void update(struct student v[]){
 FILE *f;
    int n,i;
//    struct student v[100];
     f=fopen("Update.txt","w");
for(i=0;i<n;i++)    {
        fprintf(f,"%s,",v[i].nume);
        fprintf(f,"%s,",v[i].prenume);
        fprintf(f,"%s,",v[i].sectie);
        fprintf(f,"%d,",v[i].an);
        fprintf(f,"%d,",v[i].taxa);
        fprintf(f,"%f",v[i].nota);
        fprintf(f,"\n");

    }}
int login(char user,char parola,struct date v[])
{int n,i;
    for(i=0;i<n;i++)
    if(strcmp(user,v[i].username)==0 && strcmp(parola,v[i].password)==0)
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
