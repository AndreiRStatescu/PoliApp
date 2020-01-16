#include <stdio.h>

int logare_sadministrator(){

    char nume[30], sadmin[]="1\n";
    printf("Numele de utilizator :");
    fgets(nume, 30, stdin);
    char parola[30], psadmin[]="1\n";
    printf("Parola:");fgets(parola, 30, stdin);
    if ((strcmp(nume,sadmin)==0)&&(strcmp(parola,psadmin)==0)) return 1;
    return 0;
}
void plata_taxa()
{
    char numar[20];
    printf("Introduceti numarul cardului:");
        getchar();
        fgets(numar, 20, stdin);
    while(strlen(numar)<16){
        printf("Introduceti numarul cardului:");
        getchar();
        fgets(numar, 20, stdin);}
    char data[6];int ok=0;
    while(ok==0){
    printf("Introduceti data de expirare a cardului:");fgets(data,6, stdin);

    if (data[2]=='/')
    ok=1;
    }
    char cvv[4];
    printf("Introduceti cvv-ul cardului:");getchar();
    fgets(cvv,4, stdin);
    int s;
    printf("Introduceti suma pe care doriti sa o achitati:");scanf("%d",&s);printf("Va rugam asteptati... \n");
    printf("Plata a fost finalizata cu succes"); //Urmeaza sa reducem suma din matricea de situatie
}

void cerere_transfer(){
    int i;
    printf("Numarul caminului in care doriti sa va mutati:");
    scanf("%d",&i);

}
