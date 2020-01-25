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

struct Student {
    char nume[20];
    char colaborator[20];
    char examen1[20];
    char examen2[20];
    char examen3[20];
    int zile;
    char review[20];
    char status[20];
    int suma;
};

void Login (char username[], char parola[])
{

    FILE *f;
    struct Logare log;
    f=fopen("Login.txt","r");
    int t=0;
    while(fscanf(f,"\nusername: %s", log.username)!=EOF &&fscanf(f,"\npass: %s",log.parola)!=EOF)
    if(strcmp(username,log.username)==0 && strcmp(parola,log.parola)==0)
    t=1;
    system("cls");
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

void Creare (char username[], char parola[])
{

    FILE *f;
    struct Logare log;
    f=fopen("Login.txt","a+");
    int t=0;
    while(fscanf(f,"\nusername: %s", log.username)!=EOF &&fscanf(f,"\npass: %s",log.parola)!=EOF)
    if(strcmp(username,log.username)==0)
    t=1;
    system("cls");
    if(t==1)
    {
        printf("Alegeti alt username\n");
    }
    else {
        printf("Cont creat cu succes!\n");
        fprintf(f,"\n");
        fprintf(f,"\nusername: %s", username);
        fprintf(f,"\npass: %s", parola);
    }

    fclose(f);
}

void Examene(char colaborator[])
{
     FILE *f;
    struct Student s;
    f=fopen("Erasmus.txt","r");
    int t=0;
    while(fscanf(f,"\nstudent: %s", s.nume)!=EOF &&
          fscanf(f,"\nusername: %s",s.colaborator)!=EOF &&
          fscanf(f,"\nexamen1: %s", s.examen1)!=EOF &&
          fscanf(f,"\nexamen2: %s", s.examen2)!=EOF &&
          fscanf(f,"\nexamen3: %s", s.examen3)!=EOF &&
          fscanf(f,"\nzile de practica: %d", &s.zile)!=EOF &&
          fscanf(f,"\nreview: %s", s.review)!=EOF &&
          fscanf(f,"\nstatus: %s", s.status)!=EOF &&
          fscanf(f,"\nsuma: %d", &s.suma)!=EOF)
    if(strcmp(colaborator,s.colaborator)==0)
    {
        if(strcmp("/",s.examen1)==0 && strcmp("/",s.examen2)==0 && strcmp("/",s.examen3)==0)
        printf("%s nu a participat\n",s.nume);
        else
        printf("%s, examen1: %s, examen2: %s, examen3:%s\n", s.nume, s.examen1, s.examen2, s.examen3);

    }
    printf("\n");
}

void Review(char colaborator[])
{
     FILE *f;
    struct Student s;
    f=fopen("Erasmus.txt","r");
    int t=0;
    while(fscanf(f,"\nstudent: %s", s.nume)!=EOF &&
          fscanf(f,"\nusername: %s",s.colaborator)!=EOF &&
          fscanf(f,"\nexamen1: %s", s.examen1)!=EOF &&
          fscanf(f,"\nexamen2: %s", s.examen2)!=EOF &&
          fscanf(f,"\nexamen3: %s", s.examen3)!=EOF &&
          fscanf(f,"\nzile de practica: %d", &s.zile)!=EOF &&
          fscanf(f,"\nreview: %s", s.review)!=EOF &&
            fscanf(f,"\nstatus: %s", s.status)!=EOF &&
          fscanf(f,"\nsuma: %d", &s.suma)!=EOF)
    if(strcmp(colaborator,s.colaborator)==0)
    {
        if(s.zile==0 && strcmp("/",s.review)==0)
        printf("%s nu a facut practica\n",s.nume);
        else
        printf("%s a facut %d zile de practica si review-ul sau este %s\n", s.nume, s.zile, s.review);
    }
    printf("\n");
}

void Plata(char colaborator[])
{
     FILE *f;
    struct Student s;
    f=fopen("Erasmus.txt","r");
    int t=0;
    printf("%s:\n",colaborator);
    while(fscanf(f,"\nstudent: %s", s.nume)!=EOF &&
          fscanf(f,"\nusername: %s",s.colaborator)!=EOF &&
          fscanf(f,"\nexamen1: %s", s.examen1)!=EOF &&
          fscanf(f,"\nexamen2: %s", s.examen2)!=EOF &&
          fscanf(f,"\nexamen3: %s", s.examen3)!=EOF &&
          fscanf(f,"\nzile de practica: %d", &s.zile)!=EOF &&
          fscanf(f,"\nreview: %s", s.review)!=EOF &&
          fscanf(f,"\nstatus: %s", s.status)!=EOF &&
          fscanf(f,"\nsuma: %d", &s.suma)!=EOF)
            if(strcmp(colaborator,s.colaborator)==0)
            {
                if(strcmp("platit",s.status)==0)
                printf("A platit pentru %s suma de %d roni\n",s.nume,s.suma);
                else if(strcmp("neplatit",s.status)==0)
                printf("Are de platit pentru %s suma de %d roni\n",s.nume,s.suma);
                else
                printf("Plata pentru %s in valoare de %d roni este in asteptare\n",s.nume,s.suma);
            }
        printf("\n");
        printf("Urmariti platile ce sunt in astepatare, din fisierul \"Plata\" prin optiunea 3 a meniului principal\n");
        printf("\n");
}
void Achitare(char colaborator[], char tastatura[])
{
    char nume[20];
    int i,len;
     FILE *f;
    struct Student s;
    f=fopen("Erasmus.txt","r+");
    int t=0;
    while(fscanf(f,"\nstudent: %s", s.nume)!=EOF &&
          fscanf(f,"\nusername: %s",s.colaborator)!=EOF &&
          fscanf(f,"\nexamen1: %s", s.examen1)!=EOF &&
          fscanf(f,"\nexamen2: %s", s.examen2)!=EOF &&
          fscanf(f,"\nexamen3: %s", s.examen3)!=EOF &&
          fscanf(f,"\nzile de practica: %d", &s.zile)!=EOF &&
          fscanf(f,"\nreview: %s", s.review)!=EOF &&
          fscanf(f,"\nstatus: %s", s.status)!=EOF &&
          fscanf(f,"\nsuma: %d", &s.suma)!=EOF)
            if(strcmp(colaborator,s.colaborator)==0 && strcmp(s.nume,tastatura)==0 && strcmp("neplatit",s.status)==0)
                break;

            printf("Plata in valoare de %d roni a fost realizata cu succes pentru %s!\n",s.suma, s.nume);

            int k=0;
            while(s.suma)
            {
                k++;
                s.suma=s.suma/10;
            }
                strcpy(s.status,"platit");
                len=strlen("neplatit");
                fseek(f,-len-8-k,SEEK_CUR);
                fprintf(f,"%s","platit  ");
}
void Asteptare()
{
     FILE *f;
     FILE *g;
    struct Student s;
    f=fopen("Erasmus.txt","r");
    g=fopen("Plata.txt","w");

            fprintf(g,"Plati in asteptare:\n\n");
         while(fscanf(f,"\nstudent: %s", s.nume)!=EOF &&
          fscanf(f,"\nusername: %s",s.colaborator)!=EOF &&
          fscanf(f,"\nexamen1: %s", s.examen1)!=EOF &&
          fscanf(f,"\nexamen2: %s", s.examen2)!=EOF &&
          fscanf(f,"\nexamen3: %s", s.examen3)!=EOF &&
          fscanf(f,"\nzile de practica: %d", &s.zile)!=EOF &&
          fscanf(f,"\nreview: %s", s.review)!=EOF &&
          fscanf(f,"\nstatus: %s", s.status)!=EOF &&
          fscanf(f,"\nsuma: %d", &s.suma)!=EOF)
              if(strcmp("neconfirmat",s.status)==0)
               fprintf(g,"%s -> %s - %d roni\n",s.colaborator, s.nume, s.suma);
}
int main_colaboratori()
{

    struct Logare l[50];
    struct Logare l2[50];
    int op,t;
for(;;)
{
    printf("              MENIU            \n");
    printf("0.Iesire din program\n");
    printf("1.Logare colaborator\n");
            printf("\t10.Iesire din submeniu\n");
             printf("\t11.Vizualizarea tuturor studentilor si a examenelor acestora\n");
             printf("\t12.Vizualizarea tuturor studentilor si a evidentei lor practice\n");
             printf("\t13.Evidenta platilor\n");
             printf("\t14.Achitarea unei plati\n");
    printf("2.Creare cont de colaborator\n");
    printf("3.Plati in asteptare\n");
    printf("\n\n");
    printf("Introduceti optiunea dorita:\n");
    scanf("%d", &op);
    printf("\n");
    switch(op)
    {
        case 0: return 0;
        case 1:
        {
            t=0;
            fflush(stdin);
            printf("\n\tIntroduceti username-ul: ");
            gets(l[0].username);

            printf("\tInroduceti parola: ");
            gets(l[0].parola);

            Login(l[0].username,l[0].parola);
            printf("\n");

            printf("\t     SUBMENIU       \n");
              printf("\t10.Iesire din submeniu\n");
             printf("\t11.Vizualizarea tuturor studentilor si a examenelor acestora\n");
             printf("\t12.Vizualizarea tuturor studentilor si a evidentei lor practice\n");
            printf("\t13.Evidenta platilor\n");
            printf("\t14.Achitarea unei plati\n");
            printf("\n\n");
            for(;;)
            {
                int op2;
                printf("Introduceti optiunea dorita:\n");
                scanf("%d", &op2);
                switch(op2)
                    {
                        case 10:{system("cls"); break; }
                        case 11:{ Examene(l[0].username); }break;
                        case 12:{ Review(l[0].username); }break;
                        case 13:{ Plata(l[0].username); }break;
                        case 14:{   fflush(stdin);
                                        printf("Pentru care dintre studenti doriti sa achitati plata?\n");
                                        char nume[20];
                                        fgets(nume,20,stdin);
                                        nume[strcspn(nume, "\n")] ='\0';
                                        Achitare(l[0].username,nume);
                                    }break;
                        default:printf("Aceasta optiune nu exista\n");
                    }
                    if(op2==10)
                    {
                        break;
                        t=1;
                    }
            }

        }break;
        case 2:{

        fflush(stdin);
        printf("\n\tAlegeti username-ul dorit: ");
        gets(l2[0].username);

        printf("\tAlegeti parola dorita: ");
        gets(l2[0].parola);

        Creare (l2[0].username,l2[0].parola);

        }break; system("cls");

        case 3:{
        printf("Platile in asteptare -> fisierul \"Plata\"\n");
        Asteptare();
        }break; system("cls");

        default:printf("Aceasta optiune nu exista!\n");

    }
}

    return 0;
}
