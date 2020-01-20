#include<stdio.h>
#include<string.h>

int cautare(int n)
{
    FILE *f=fopen("admin.int", "r");
    char v[300], m='0'+n;
    while(fgets(v, 300, f)!=NULL)
        if((v[0]==m)&&(v[1]==','))
        {
            fclose(f);
            return 1;
        }
    fclose(f);
    return 0;
}
void a_creeaza_cont()
{
    FILE *f=fopen("admin.int", "a");
    char b[30], v[30];
    int number;
    printf("Introduceti numarul caminului pentru care creati noul cont de adminstrator:");
    scanf("%d", &number);
    getchar();
    if(cautare(number)==0)
    {
        printf("Introduceti numele de utilizator:");
        fgets(b, 30, stdin);
        b[strlen(b)-1]='\0';
        printf("Introduceti parola:");
        fgets(v, 30, stdin);
        fprintf(f, "%d,%s,%s", number, b, v);
        printf("Contul a fost creat cu succes!");
    }
    else
        printf("Contul nu se poate crea, exista deja administrator pentru caminul %d, incercati sa stergeti contul respectiv inainte.", number);
    fclose(f);
}

void s_creeaza_cont(int nr, int nc)
{
    FILE *f=fopen("student.int", "a");
    int an;
    char nume[30], prenume[30], parola[30];
    printf("Introduceti anul in care se afla studentul:");
    scanf("%d", &an);
    getchar();
    printf("Introduceti numele studenului:");
    fgets(nume, 30, stdin);
    printf("Intoduceti prenumele studentului:");
    fgets(prenume, 30, stdin);
    printf("Introduceti parola contului:");
    fgets(parola, 30, stdin);
    nume[strlen(nume)-1]='\0';
    prenume[strlen(prenume)-1]='\0';
    parola[strlen(parola)-1]='\0';
    fprintf(f, "%d,%s,%s,%s,%d,%d,0 \n", an, nume, prenume, parola, nr, nc);
    fclose(f);
}
