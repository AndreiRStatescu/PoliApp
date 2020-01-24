#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Afisare(char c[10000])
{
    printf("\nCodul este: \n%s",c);
}
void Creep(char c[10000])
{
    int i,n=strlen(c);
    for(i=0; i<n-1; i++)
    {
        if(i%3==0)
            c[i]=c[i]-c[n-1];
        else
            c[i]=c[i]+'a';

    }

}
void DeCreep(char c[10000])
{
    int i,n=strlen(c);
    for(i=n-2; i>=0; i--)
    {
        if(i%3==0)
            c[i]=c[i]+c[n-1];
        else
            c[i]=c[i]-'a';

    }
}

void CriptareParola(char c[10000])
{
    done(c);
    stele1(c);
    Creep(c);
    criptare(c);
    criptare10(c);

}
void DecriptareParola(char c[10000])
{
    decriptare10(c);
    decriptare(c);
    DeCreep(c);
    stele2(c);
    undone(c);
}
typedef struct
{
    char nume[20],prenume[20];
    int an;
    char sectie[9];
    char parola[20];
    char colab[20];
} Student;
char *Colab[3]= {"Erasmus","administratie","practica"};

void citire(int n,Student s[100])
{
    char r[120];//vectorul asta il folosesc sa-mi treaca peste spatiul pe care il face atunci cand citesc un int inainte de un sir de caract

    if(n==1)
        printf("\nAti ales sa introduceti datele ale unui singur student: ");
    else
        printf("\nAti ales sa introduceti datele a %d studenti: ",n);
    for(int i=0; i<n; i++)
    {
        printf("\nStudentul %d",i+1);
        fgets(r,12,stdin);
        printf("\nIntroduceti numele studentului: ");
        fgets(s[i].nume,19,stdin);

        printf("\nIntroduceti prenumele studentului: ");
        fgets(s[i].prenume,19,stdin);

        printf("\nIntroduceti o parola pentru student: ");
        fgets(s[i].parola,19,stdin);
        CriptareParola(s[i].parola);

        printf("\nIntroduceti sectia in care se afla studentul: ");
        fgets(s[i].sectie,8,stdin);

        printf("\nIn cazul in care studentul are colaboratori atunci introduceti una dintre urmatoarele : Erasmus sau firma la care face practica.Iar daca nu are atunci tastati - ");
        fgets(s[i].colab,19,stdin);

        printf("\nIntroduceti anul in care se afla studentul: ");
        scanf("%d",&s[i].an);

    }
}
typedef struct
{
    char user[20];
    char parola[20];
} Logare;

typedef struct
{
    char user[20];
    char parola[20];
} Org;
void Delete_fct(char r[100])
{
    FILE *f;
    f=fopen("colaboratori.txt","r");
    if(!f)
    {
        printf("Nu merge alt fisier");
        exit(3);
    }
    char s[100][100];
    int i,n=0;
    while(!feof(f))
    {
        fscanf(f,"\n%s",s[n]);
        n++;
    }

    fclose(f);
    r[strlen(r)-1]='\0';
    f=fopen("colaboratori.txt","w");
    if(!f)
    {
        printf("Nu merge alt fisier");
        exit(4);
    }

    for(i=0; i<n; i++)
        if(strcmp(s[i],r)!=0)
            fprintf(f,"%s\n",s[i]);
    fclose(f);
}
void Add_fct(char r[100])
{
    FILE *f;
    f=fopen("colaboratori.txt","r");
    if(!f)
    {
        printf("Nu merge alt fisier");
        exit(3);
    }
    char s[100][100];
    int i,n=0;
    while(!feof(f))
    {
        fscanf(f,"\n%s",s[n]);
        n++;
    }

    fclose(f);
    r[strlen(r)-1]='\0';
    f=fopen("colaboratori.txt","w");
    if(!f)
    {
        printf("Nu merge alt fisier");
        exit(4);
    }
    n++;
    strcpy(s[n-1],r);
    for(i=0; i<n; i++)
        fprintf(f,"%s\n",s[i]);
    fclose(f);

}
void organizator(int n,Org o[100])
{
    int x,k;
    char r[100];
    int ok=0;
    Logare log;
    fgetc(stdin);
    printf("\nPentru a te loga trebuie sa introduci un user si o parola.");
    printf("\nUser: ");
    fgets(log.user,19,stdin);
    printf("\nParola: ");
    fgets(log.parola,19,stdin);
    log.user[strlen(log.user)-1]='\0';
    log.parola[strlen(log.parola)-1]='\0';
    for(int i=0; i<n; i++)
        if(strcmp(log.user,o[i].user)==0 && strcmp(log.parola,o[i].parola)==0)
        {
            ok=1;
        }

    if(ok==1)
        printf("\nTe-ai logat cu succes!");
    else
    {
        printf("\nUser sau parola gresita sau nu exista acest utilizator");
        exit(2);
    }

    printf("\nPentru a incepe o noua colaborare apasati tasta 1.");
    printf("\nDaca doriti sa anulati o colaborare apasati 0 ");
    scanf("%d",&x);


    do
    {
        switch(x)
        {
        case 0 :
            printf("Introduceti firma cu care doriti sa incetati colaborarea.");
            fgets(r,19,stdin);
            fgets(r,19,stdin);
            Delete_fct(r);
            break;
        case 1 :
            printf("Introduceti firma cu care doriti sa incepeti o noua colaborare.");
            fgets(r,19,stdin);
            fgets(r,19,stdin);
            Add_fct(r);
            break;


        default : "Out of memory :D"
            ;
            break;
        }
        printf("\nDaca doriti sa reintroduceti un colaborator sau sa anulati o colaborare ,apasati 1 respectiv 0, sau 2 pentru a iesi din program");
        scanf("%d",&x);
    }
    while(x<2);
    printf("Va multumim!");
}
void main_studenti()
{
    int n;
    printf("Introduceti numarul de studenti a caror date vor fi adaugate: ");
    scanf("%d",&n);
    Student s[100];
    citire(n,s);
//afisarea studentilor
    printf("\nDatele studentilor sunt :");
    for(int i=0; i<n; i++)
    {
        printf("\n%d:**************************",i+1);
        printf("\nNumele studentului este : ");
        printf(" %s",s[i].nume);

        printf("\nPrenumele studentului este : ");
        printf(" %s",s[i].prenume);

        printf("\nSectia la care se afla studentul este : ");
        printf(" %s",s[i].sectie);

        printf("\nAnul in care este studentul este : ");
        printf(" %d",s[i].an);

        printf("\nColaborator : ");
        printf(" %s",s[i].colab);

        printf("\nParola studentului este : ");
        DecriptareParola(s[i].parola);
        printf(" %s",s[i].parola);
        CriptareParola(s[i].parola);
    }

}
void main_organizator()
{
    FILE *f;
    int n=0;
    Org o[100];
    f=fopen("organizator.txt","r");
    if(!f)
    {
        printf("Nu merge fisierul");
        exit(1);
    }
    while(fscanf(f,"\nuser: %s",o[n].user)!=EOF &&fscanf(f,"\npass: %s",o[n].parola)!=EOF)
        n++;
    fclose(f);
    printf("%d",n);
    for(int i=0; i<n; i++)
    {
        printf("\nuser: %s",o[i].user);
        printf("\nparola: %s",o[i].parola);
    }
    organizator(n,o);
}



