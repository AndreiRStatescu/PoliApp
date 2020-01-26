#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void prprenume(char s[100])
{
    char *pr,t[100];
    pr=strtok(s," ");

    strcpy(s,pr);
}

void creare_cont_secretar(struct user users[],int *nrUsers)
{
    *nrUsers=*nrUsers+1;
    char nume[30],prenume[30],parola[30];
    char a[30],b[30],q[100];
    printf("Nume:");
    fgets(nume,30,stdin);
    nume[strcspn(nume,"\n")]='\0';
    strcpy(users[*nrUsers-1].nume,nume);
    printf("Prenume:");
    fgets(prenume,30,stdin);
    prenume[strcspn(prenume,"\n")]='\0';
    strcpy(users[*nrUsers-1].prenume,prenume);
    printf("Parola:");
    fgets(parola,30,stdin);
    parola[strcspn(parola,"\n")]='\0';


    strcpy(a,nume);
    strlwr(a);
    strcpy(b,prenume);
    strlwr(b);
    strcpy(q,a);
    strcat(q,b);
    strcat(q,"@upt.ro");
    //printf("%d",*nrUsers);

    strcpy(users[*nrUsers-1].username,q);
    strcpy(users[*nrUsers-1].type,"secretar");

    strcpy(users[*nrUsers-1].password,parola);

}

void stergere_cont_secretar(struct user users[],int *nrUsers)
{
    char nume[20],prenume[20],buf[50];int i,j;
    printf("Nume:");
    fgets(nume,20,stdin);nume[strcspn(nume,"\n")]='\0';
    printf("Prenume:");
    fgets(prenume,20,stdin);prenume[strcspn(prenume,"\n")]='\0';
    strcpy(buf,nume);
    strcat(buf,prenume);strcat(buf,"@upt.ro");


    for(i=0; i<*nrUsers; i++)
    {
        if(strcmp(buf,users[i].username)==0)
        {
            for(j=i; j<*nrUsers-1; j++)
            {strcpy(users[j].username,users[j+1].username);
               strcpy(users[j].type,users[j+1].username);
               strcpy(users[j].password,users[j+1].password);


            }
            i=i-1;
            *nrUsers=*nrUsers-1;
        }
    }

}

void criptare(char s[100])
{
    int i;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='A' && s[i]<='N')
            s[i]+=38;
        else if(s[i]>='l' && s[i]<='z')
            s[i]-=40;
        else if (s[i]>='0' && s[i]<='9')
            s[i]-=48;
    }
    strrev(s);
}

void decriptare(char s[100])
{
    int i;
    strrev(s);
    for(i=0;i<strlen(s);i++)
    {
        if((s[i]-38)>='A' && (s[i]-38)<='N')
            s[i]-=38;
        else if((s[i]+40)>='l' && (s[i]+40)<='z')
            s[i]+=40;
        else if (s[i]>=0 && s[i]<=9)
            s[i]+=48;
    }

}
void Read_Students(struct student students[],struct user users[] ,int *nr, char finput[],int *nrUsers)
{
    FILE *fr = fopen(finput, "r");
    char line[101], *p,q[100],o[100],h[100],r[100],w[100];
    char a[101];

    int k=0,i,ok,x=0;
    while(fgets(line,100,fr))
    {
        p=strtok(line, ",");
        strcpy(students[k].nume,p);
        strcpy(users[*nrUsers].nume,p);
        p=strtok(NULL, ",");
        strcpy(students[k].prenume,p);
        strcpy(users[*nrUsers].prenume,p);
        ok=0;
        p=strtok(NULL, ",");
        strcpy(users[*nrUsers].password,p);

        p=strtok(NULL, ",");
        students[k].an = atoi(p);
        p=strtok(NULL, ",");
        strcpy(students[k].sectie,p);
        p=strtok(NULL, ",");
        students[k].taxa = atof(p);

        strcpy(users[*nrUsers].username,"student");

        strcpy(o,students[k].nume);

        strcpy(h,students[k].prenume);
        prprenume(o);
        prprenume(h);

        strcpy(q,strlwr(o));
        strcat(q,strlwr(h));

        strcpy(r,q);
        strcat(r,"@upt.student.ro");
        strcpy(users[*nrUsers].username,r);
       /* x=0;
        for(i=0; i<k; i++)
        {
            strcpy(a,students[i].prenume);
            //prprenume(a);
            strlwr(a);
            if(strcmp(students[i].nume,students[k].nume)==0 && strcmp(a,h)==0)
            {
                x++;
            }
        }
        char s[100];
        if(x==0)
            strcpy(users[k].numeUtilizator,r);
        else
        {
            itoa(x,s,10);
            strcat(q,s);
            strcpy(users[k].numeUtilizator,strcat(q,"@upt.student.ro"));

        }*/

        *nrUsers++;
        k++;
    }
    *nr=k;
}
