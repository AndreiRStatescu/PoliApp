
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
    char username[100],password[31],type[31],nume[31],prenume[31];
}users[301];

struct materi
{
    char numeM[20],numeP[20][31] , prenumeP[20][31] ;
    int nr_profesori,anStudi,credite;
}materii[51];

struct sali
{
    char numes[20] , tip_sala[20] ;
    int nr_locuri;
}sali[200];

struct profesori
{
    char nume[100],materii[100][100],preferinte[100];
    int nrMaterii,oreMaterii[100];
}profs[100];

int main()
{

    int i,j, nrStud,nrUtilizatori,nrProfs,nrMat,nrSali,showToDo=0;
    Read_Materi(materii,&nrMat,"InputMaterii.txt");
    Read_Sali(sali,&nrSali,"InputSali.txt");
    read_prof(profs,&nrProfs,"InputProfs.txt");
    char line[101];
    GetStudents(students,&nrStud,nrMat,"StudentsData.txt");
    GetUsers(users,&nrUtilizatori,"UsersData.txt");
    //FILE *f = fopen("StudentsData.txt", "r");
  /*  while(fgets(line,100,f))
    {
        line[strlen(line)-1]='\0';
        strcpy(materii[nrMat++],line);
    }*/


    for(;;)
    {


        char username[100],password[31];
        int poz;
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
            system("cls");
            printf("Nume Utilizator: ");
            scanf("%s",username);
            printf("Parola: ");
            scanf("%s",password);
            poz=login(username,password,users,"admin",nrUtilizatori);
            if(poz!=-1)
            for(;;)
            {
                int undo=0;
                system("cls");
                for(i=0; i<nrUtilizatori; i++)
                {
                    printf("%s %s %s",users[i].username,users[i].password,users[i].type);
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
            system("cls");
            printf("Nume Utilizator: ");
            scanf("%s",username);
            printf("Parola: ");
            scanf("%s",password);
            poz=login(username,password,users,"secretar",nrUtilizatori);
            if(poz!=-1)
            for(;;)
            {
                int undo=0,r,an;
                system("cls");
                if(showToDo==1)
                    ShowToDo();
                printf("Apasati 1 pentru a adauga note\n");
                printf("Apasati 2 pentru a schimba o nota\n");
                printf("Apasati 3 pentru a inscrie studentii\n");
                if(showToDo==0)
                    printf("Apasati 4 pentru a afisa lista de cereri\n");
                else
                    printf("Apasati 4 pentru a ascunde lista de cereri\n");
                printf("Apasati 5 pentru a sterge din lista de cereri\n");
                printf("Apasati 6 pentru a achita o plata\n");
                printf("Apasati 7 pentru a transfera un student\n");
                printf("Apasati 8 pentru a exmatricula un student\n");
                printf("Apasati 9 pentru a elibera contract de studiu\n");
                printf("Apasati 0 pentru a merge inapoi\n");
                char nume[31],prenume[31], sectie[20];
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
                            printf("Nota lui %s %s la %s este: %.2f\n", students[i].nume, students[i].prenume, materii[j].numeM,students[i].nota[j]);

                    schimbare_nota(students,nrStud,materii,nrMat);


                    break;
                case 3:
                    Read_Students(students,users,&nrStud,"InputStudents.csv",&nrUtilizatori);
                    break;
                case 4:
                    if(showToDo==0)
                        showToDo=1;
                    else
                        showToDo=0;
                    break;
                case 5:
                    printf("Alegeti ce cerere sa fie stearsa: ");
                    scanf("%d",r);
                    stergereLista(r);
                    break;
                case 6:
                    plata(students,nrStud);
                    break;
                case 7:
                    printf("Nume: ");scanf("%s",nume);
                    printf("Prenume: ");scanf("%s",prenume);
                    printf("Noua sectie: ");scanf("%s",sectie);
                    transfer(students,nrStud,nume,prenume,sectie);
                    break;
                case 8:
                    printf("Nume: ");scanf("%s",nume);
                    printf("Prenume: ");scanf("%s",prenume);
                    eliminare(students,nume,prenume,nrStud,nrMat);
                    nrStud--;
                    break;
                case 9:
                    printf("Nume: ");scanf("%s",nume);
                    printf("Prenume: ");scanf("%s",prenume);
                    printf("An: ");scanf("%d",&an);
                    eliberare(materii,nume,prenume,an,nrMat);
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
            system("cls");
            printf("Nume Utilizator: ");
            scanf("%s",username);
            printf("Parola: ");
            scanf("%s",password);
            poz=login(username,password,users,"student",nrUtilizatori);
            if(poz!=-1)
                for(;;)
                {
                    int undo=0;
                    system("cls");
                    printf("Apasati 1 pentru a depune cerere de transfer\n");
                    printf("Apasati 2 pentru a depune cerere de achitare plata\n");
                    printf("Apasati 0 pentru a merge inapoi\n");
                    int op;
                    scanf("%d",&op);
                    getchar();
                    switch(op)
                    {
                        case 1:
                            cerereTransfer(users[poz].nume,users[poz].prenume);
                            break;
                        case 2:
                            cererePlata(users[poz].nume,users[poz].prenume);
                            break;
                        case 0:
                            undo=1;
                            break;
                    }
                    if(undo==1)
                        break;

                }
            break;
        case 0:
            updateuser(users,nrUtilizatori);
            //updateStud(students,nrStud,nrMat); //nu stiu de ce nu merge
            return 0;
        }
    }

    return 0;
}

