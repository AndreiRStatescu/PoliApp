#include <stdio.h>
#include "casi.h"
#include "ale.h"

int main()
{
    int k,n,camin;
    printf("Bine ai venit pe alicatia Camine.app \n Inainte da a te loga te rog selecteaza una dintre optiunile urmatoare: \n 1.Sunt SuperAdmin; \n 2.Sunt admin; \n 3.Sunt student.");
    printf("\nOptiunea ta este:");scanf("%d",&k);
    getchar();
    switch (k){
    case 1:
        k=0;
        while(k==0){
        k=logare_sadministrator();
        if (k==0) printf("Nume de utilizator sau parola incorecta! \n");
        }
        printf("Bine ai venit! Iata care sunt optiunile tale:\n 1. Creaza un cont de admin; \n 2. Sterge un cont de admin.\n Ce alegi sa faci astazi:");
        scanf("%d",&k);
        switch (k){
        case 1:
            //Urmeaza
        break;
        case 2:
        printf("Introduceti numarul caminului de la care doriti sa stergeti contul de administrator:");
        scanf("%d",&n);
        //Urmeaza
        break;
    }
    break;
    case 2:
    //Aici vine logare admin
    printf("Bine ai venit! Iata care sunt optiunile tale:\n 1. Adauga un student; \n 2.Elimina un student;\n 3.Muta un student; \n 4.Situatia pe camin.\n Ce alegi sa faci astazi:");
        scanf("%d",&k);
    switch (k){
        case 1:
        //aici vine functia "Adauga un student"
        break;
        case 2:
        //aici vine functia "Elimina un student"
        break;
        case 3:
        //aici vine functia "Muta un student"
        break;
        case 4:
            printf("Care este caminul la care esti administrator?");scanf("%d",&camin);//cand va fi gata logarea,fiecare admin va putea vedea doar situatia de pe caminul lui
            afisare_situatie(camin);
        break;
       }
    break;
    case 3:
    //Aici vine logare student
    printf("Bine ai venit! Iata care sunt optiunile tale:\n 1.Plata taxa; \n 2. Cerere de transfer. \n Ce alegi sa faci astazi:");
        scanf("%d",&k);

    switch (k){
        case 1:
        plata_taxa();
        break;
        case 2:
        cerere_transfer();
        break;
    break;}
}
}
