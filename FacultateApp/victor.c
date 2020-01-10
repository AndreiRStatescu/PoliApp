#include<stdio.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
};
struct date
{char username[30];
char password[30];

};

void update(struct student v[]){
 FILE *f;
    int n,i;
//    struct student v[100];
     f=fopen("C:\\Users\\victo\\Desktop\\Probleme lab\\Update.txt","w");
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
