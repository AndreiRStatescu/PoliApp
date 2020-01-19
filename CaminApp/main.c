#include <stdio.h>
#include "casi.h"
#include "andre.h"
int main()
{
    int k,n,p;

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

        break;
    }
    break;
    case 2:
       p=0;
        while(p==0){
        p=cauta_admin();
        if (p==0) printf("Ati introdus un camp incorect! \n");
        }

    printf("Bine ai venit! Iata care sunt optiunile tale:\n 1. Adauga un student; \n 2.Elimina un student;\n 3.Muta un student; \n 4.Situatia pe camin.\n Ce alegi sa faci astazi:");
        scanf("%d",&k);
    switch (k){
        case 1:
        //aici vine functia "Adauga un student"
        break;
        case 2:

        break;
        case 3:
        //aici vine functia "Muta un student"
        break;
        case 4:
        //aici vine functia "Achita un student"
        break;
        case 5:
        //aici vine functia "Situatia pe camin"
        break;}
    break;
    case 3:
        k=0;
        while(k==0){
        k=cauta_student();
        if (k==0) printf("Ati introdus un camp incorect! \n");
        }
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
