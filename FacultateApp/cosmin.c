#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
};

void inserare_nota(struct student stud[], int n,char materii[][51], int m/*nr materii*/)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("Nota lui %s %s la %s este: ", stud[i].nume, stud[i].prenume, materii[j]);
			scanf("%f", &stud[i].nota);
		}
}
void schimbare_nota(struct student stud[],int nrStud,char nume[],char prenume [],float nota_noua,int indice_materie)
{ int i;
    char numE[30],prenumE[30];
printf("Dati numele dorit %s :",numE);
    fgets(numE,29,stdin);
printf("Dati prenume dorit %s :",prenumE);
    fgets(prenumE,29,stdin);
printf("Dati nota noua %f :",nota_noua);
    scanf("%f",&nota_noua);
for(i=0;i<nrStud;i++)
    if(strcmp(numE,stud[i].nume)==0 && (strcmp(prenumE,stud[i].prenume)==0))
         stud[i].nota=nota_noua;


}
