
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cosmin.h"
#include "dani.h"
#include "kristi.h"
#include "tania.h"
#include "victor.h"


struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota[31];

} students[301];

struct user
{
    char numeUtilizator[100],parola[31],tipUtilizator[31];
} users[301];

int main()
{

    int i,j, nrStud,nrUtilizatori,nrMat=0;
    char materii[20][31], line[31];
    FILE *f = fopen("InputMaterii.txt", "r");
    while(fgets(line,30,f))
    {
        line[strlen(line)-1]='\0';
        strcpy(materii[nrMat++],line);
    }



    Read_Students(students,users,&nrStud,"InputStudents.csv",&nrUtilizatori);

    for(i=0; i<nrStud; i++)
    {
        printf("%s, %s, %s, %s, %s, %d, %s\n",students[i].nume,students[i].prenume,users[i].parola,users[i].tipUtilizator,users[i].numeUtilizator,students[i].an,students[i].sectie);
    }


    for(;;)
    {
        system("cls");

        printf("Apasati 1 pentru a va loga ca admin\n");
        printf("Apasati 2 pentru a va loga ca secretar\n");
        printf("Apasati 3 pentru a va loga ca student\n");
        printf("Apasati 0 pentru a iesi\n");
        int opt;
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            for(;;)
            {
                int undo=0;
                system("cls");
                for(i=0; i<nrUtilizatori; i++)
                {
                    printf("%s %s %s",users[i].numeUtilizator,users[i].parola,users[i].tipUtilizator);
                    printf("\n");
                }


                printf("Apasati 1 pentru a crea un cont de secretar\n");
                printf("Apasati 2 pentru a sterge un cont de secretar\n");
                printf("Apasati 0 pentru a merge inapoi\n");

                int op;
                scanf("%d",&op);
                getchar();
                switch(op)
                {
                case 1:
                    creare_cont_secretar(users,&nrUtilizatori);

                    break;
                case 2:
                    stergere_cont_secretar(users,&nrUtilizatori);

                    break;
                case 0:
                    undo=1;
                    break;

                }
                if(undo==1)
                    break;
            }
            break;
        case 2:
            for(;;)
            {
                int undo=0;
                system("cls");
                printf("Apasati 1 pentru a adauga note\n");
                printf("Apasati 2 pentru a schimba o nota\n");
                printf("Apasati 0 pentru a merge inapoi\n");

                int op;
                scanf("%d",&op);
                getchar();
                switch(op)
                {
                case 1:

                    inserare_note(students,nrStud,materii,nrMat);

                    break;
                case 2:
                    for (i = 0; i < nrStud; i++)
                        for (j = 0; j < nrMat; j++)
                            printf("Nota lui %s %s la %s este: %.2f\n", students[i].nume, students[i].prenume, materii[j],students[i].nota[j]);

                    schimbare_nota(students,nrStud,materii,nrMat);


                    break;
                case 0:
                    undo=1;
                    break;

                }
                if(undo==1)
                    break;
            }
            break;
        case 3:
            break;
        case 0:
            return 0;
        }
    }


    return 0;
}

