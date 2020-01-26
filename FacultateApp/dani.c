#include<stdio.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota[31];
};
struct user
{
    char username[100],password[31],type[31],nume[31],prenume[31];
};

void ShowToDo()
{
    FILE *f;
    char rand[101];
    int k=0;
    printf("Lista de cereri:\n");
    f=fopen("ToDoList.txt","r");


    while(fgets(rand,100,f))
    {
        k++;
        printf("%d.%s\n",k,rand);
    }
    if(k==0)
        printf("Nu sunt cereri\n");
}
void cerereTransfer(char nume[],char prenume[])
{
    char sectie[31];
    printf("Introduceti sectia dorita: ");
    scanf("%s",sectie);
    FILE *f;
    char rand[100]="";

    f=fopen("ToDoList.txt","a");

    strcat(rand,nume);
    strcat(rand," ");
    strcat(rand, prenume);
    strcat(rand," doreste sa se transfere la sectia ");
    strcat(rand,sectie);
    fprintf(f,"%s\n",rand);
    fclose(f);

}
