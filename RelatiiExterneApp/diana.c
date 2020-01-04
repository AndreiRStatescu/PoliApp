#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void criptare10(char s[101])
{
    int i;
    int n=strlen(s);
    char aux;
    for(i=0;i<n/2;i++)
    {
        aux=s[i];
        s[i]=s[n-i-1];
        s[n -i-1]=aux;
    }

}
void decriptare10(char s[101])
{
    criptare10(s);
}

struct Logare {
    char username[20];
    char parola[20];
};
 struct Erasmus
  {
        char examen1[20];
        char examen2[20];
        char examen3[20];
        char examen4[20];
        char examen5[20];
        char examen6[20];
  };
void Login (char username[], char parola[])
{

    FILE *f;
    struct Logare log;
    struct Erasmus ex;
    f=fopen("evidenta.txt","r");
    int t=0;
    while(fscanf(f,"\nusername: %s", log.username)!=EOF &&fscanf(f,"\npass: %s",log.parola)!=EOF && fscanf(f,"\nexamen1: %s",ex.examen1)!=EOF && fscanf(f,"\nexamen2: %s",ex.examen2)!=EOF && fscanf(f,"\nexamen3: %s",ex.examen3)!=EOF && fscanf(f,"\nexamen4: %s",ex.examen4)!=EOF && fscanf(f,"\nexamen5: %s",ex.examen5)!=EOF && fscanf(f,"\nexamen6: %s",ex.examen6)!=EOF)
    if(strcmp(username,log.username)==0 && strcmp(parola,log.parola)==0)
    t=1;

    if(t==1)
    {
        printf("V-ati logat cu succes! \n");
    }
    else
    {
        printf("Username sau parola incorecta! \n");
        printf("Nu mai puteti utiliza aplicatia!\n");
        exit(0);
    }

    fclose(f);
}
void Creare (char username2[], char parola2[])
{

    FILE *f;
    struct Logare log;
   struct Erasmus ex;
   char aux[]="\\";
    f=fopen("evidenta.txt","a+");
    int t=0;
    while(fscanf(f,"\nusername: %s", log.username)!=EOF &&fscanf(f,"\npass: %s",log.parola)!=EOF && fscanf(f,"\nexamen1: %s",ex.examen1)!=EOF && fscanf(f,"\nexamen2: %s",ex.examen2)!=EOF && fscanf(f,"\nexamen3: %s",ex.examen3)!=EOF && fscanf(f,"\nexamen4: %s",ex.examen4)!=EOF && fscanf(f,"\nexamen5: %s",ex.examen5)!=EOF && fscanf(f,"\nexamen6: %s",ex.examen6)!=EOF)
    if(strcmp(username2,log.username)==0)
    t=1;
    if(t==1)
    {
        printf("Alegeti alt username\n");
    }
    else {
        printf("Cont creat cu succes!\n");
        fprintf(f,"\n");
         fprintf(f,"\nusername: %s", username2);
        fprintf(f,"\npass: %s", parola2);
        fprintf(f,"\nexamen1: %s", aux);
        fprintf(f,"\nexamen2: %s", aux);
        fprintf(f,"\nexamen3: %s", aux);
        fprintf(f,"\nexamen4: %s", aux);
        fprintf(f,"\nexamen5: %s", aux);
        fprintf(f,"\nexamen6: %s", aux);
    }

    fclose(f);
}

void Erasmus(char username3[])
{
     FILE *f;
     char sir="luat";
    struct Erasmus ex;
    struct Logare log;
    f=fopen("evidenta.txt","r");
    int e1=0,e2=0,e3=0,e4=0,e5=0,e6=0, t=0;
    while(fscanf(f,"\nusername: %s", log.username)!=EOF &&fscanf(f,"\npass: %s",log.parola) && fscanf(f,"\nexamen1: %s",ex.examen1)!=EOF && fscanf(f,"\nexamen2: %s",ex.examen2)!=EOF && fscanf(f,"\nexamen3: %s",ex.examen3)!=EOF && fscanf(f,"\nexamen4: %s",ex.examen4)!=EOF && fscanf(f,"\nexamen5: %s",ex.examen5)!=EOF && fscanf(f,"\nexamen6: %s",ex.examen6)!=EOF)
    {
            if(strcmp(username3,log.username)==0)
                t=1;
            if(strcmp(username3,log.username)==0 && strcmp("luat",ex.examen1)==0)
                e1=1;
            if(strcmp(username3,log.username)==0 && strcmp("luat",ex.examen2)==0)
                e2=1;
            if(strcmp(username3,log.username)==0 && strcmp("luat",ex.examen3)==0)
                e3=1;
            if(strcmp(username3,log.username)==0 && strcmp("luat",ex.examen4)==0)
                e4=1;
            if(strcmp(username3,log.username)==0 && strcmp("luat",ex.examen5)==0)
                e5=1;
            if(strcmp(username3,log.username)==0 && strcmp("luat",ex.examen6)==0)
                e6=1;

        }

    if(t==1 && e1==0 && e2==0 && e3==0 && e4==0 && e5==0 && e6==0)
    printf("Nu ati participat la examene\n\n");

   else if(t==1)
        {
            printf("Ati luat examenele:\n");
            if(e1==1) printf("1\n");
            if(e2==1) printf("2\n");
            if(e3==1) printf("3\n");
            if(e4==1) printf("4\n");
            if(e5==1) printf("5\n");
            if(e6==1) printf("6\n");
        }
    else
    printf("Nu existati in baza de date\n\n");

    fclose(f);

}

 int main_colaboratori ()
 {
    int op;
    struct Logare l2[20];
    struct Logare l3[20];
    struct Erasmus l4[30];


    printf("              MENIU            \n");
    printf("0.Iesire din program\n");
    printf("1.Logare\n");
    printf("2.Creare cont\n");
    printf("3.Vizualizare examene\n");
    printf("\n\n");
for(;;)
{
    printf("Introduceti optiunea dorita:\n");
    scanf("%d", &op);
    printf("\n");
    switch(op)
    {
        case 0: return 0;
        case 1:
        {
            struct Logare l[20];

            fflush(stdin);
            printf("\n\tIntroduceti username-ul: ");
            gets(l[20].username);

            printf("\tInroduceti parola: ");
            gets(l[20].parola);

            Login(l[20].username,l[20].parola);
            printf("\n");

        }break;
        case 2:{
        fflush(stdin);
        printf("\n\tAlegeti username-ul dorit: ");
        gets(l2[20].username);

        printf("\tAlegeti parola dorita: ");
        gets(l2[20].parola);

        Creare (l2[20].username,l2[20].parola);

        }break;

        case 3:
        {
        fflush(stdin);
        printf("\n\tIntroduceti username-ul dumneavoastra: ");
        gets(l3[20].username);
        Erasmus (l3[20].username);

        }break;


        default: printf("Nu exista aceasta optiune\n");
    }

}
}


