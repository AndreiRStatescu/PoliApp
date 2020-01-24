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





void done(char sir[])
{
    int i;
    for(i=0; i<=strlen(sir); i++)
        if (sir[i]=='a'||sir[i]=='e'||sir[i]=='o'||sir[i]=='u'||sir[i]=='i')
            sir[i]=sir[i]-'a'+'A';
}
void undone(char sir[])
{
    int i;
    for(i=0; i<=strlen(sir); i++)
        if(sir[i]=='A'||sir[i]=='E'||sir[i]=='O'||sir[i]=='U'||sir[i]=='I')
            sir[i]=sir[i]-'A'+'a';
}

void criptare (char s[101])
{
    int i;
    for(i=0; i<strlen(s); i++)
    {
        if(i%2==0)
            s[i]=s[i]+3;
        else
            s[i]=s[i]-1;

    }
    //strrev(s);
}
void decriptare (char s[101])
{
    //strrev(s);

    int i;
    for(i=0; i<strlen(s); i++)
    {
        if(i%2==0)
            s[i]=s[i]-3;
        else
            s[i]=s[i]+1;

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

        printf("\nIn cazul in care studentul are colaboratori atunci introduceti una dintre urmatoarele : Erasmus,administratie sau firma la care face practica.Iar daca nu are atunci tastati - ");
        fgets(s[i].colab,19,stdin);

        printf("\nIntroduceti anul in care se afla studentul: ");
        scanf("%d",&s[i].an);

    }
}
typedef struct{
    char user[20];
    char parola[20];
}Logare;

void organizator(int n,Student s[100])
{
    int x,k;
    char r[100];
    fgets(r,99,stdin);//aceeasi chestie ca mai sus
    int ok=0;
    Logare log;
    printf("\nPentru a te loga trebuie sa introduci un user si o parola.(User-ul este numele)");
    printf("\nUser: ");
    fgets(log.user,19,stdin);
    printf("\nParola: ");
    fgets(log.parola,19,stdin);
    for(int i=0;i<n;i++)
{
    DecriptareParola(s[i].parola);
     if(strcmp(log.user,s[i].nume)==0 && strcmp(log.parola,s[i].parola)==0)
            {ok=1;
            k=i;
            }
    CriptareParola(s[i].parola);
}
    if(ok==1)
        printf("\nTe-ai logat cu succes!");
    else
        printf("\nUser sau parola gresita sau nu exista acest utilizator");

    printf("\nPentru a incepe o noua colaborare apasati tasta 1 ,daca doriti sa anulati o colaborare apasati 0 ");
    scanf("%d",&x);


    do{
        switch(x)
        {
            case 0 :strcpy(s[k].colab,"-");break;
            case 1 :printf("\nIntroduceti colaborarea(Firma/Erasmus/administratie): ");
                    fgets(r,19,stdin);
                    fgets(r,19,stdin);
                    strcpy(s[k].colab,r);
                    break;

            default : "Out of memory :D";break;
        }
        printf("\nDaca doriti sa reintroduceti un colaborator sau sa anulati o colaborare ,apasati 1 respectiv 0 sau 2 pentru a iesi ");
      scanf("%d",&x);
    }while(x<2);
    printf("\n Colaborarea dvs. este : %s",s[k].colab);
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
    organizator(n,s);

}




