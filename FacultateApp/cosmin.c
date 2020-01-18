#include<stdio.h>

#include <string.h>
#include <stdlib.h>

struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota[31];
};

void inserare_note(struct student stud[], int n,char materii[][31], int m)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("Nota lui %s %s la %s este: ", stud[i].nume, stud[i].prenume, materii[j]);
			scanf("%f", &stud[i].nota[j]);
		}
}
void schimbare_nota(struct student stud[], int n,char materii[][31], int m)
{
    int i,j;
    char numE[31],prenumE[31],mat[31];
    float nota_noua;
    printf("Dati numele dorit: ");
    fgets(numE,30,stdin);
    numE[strlen(numE)-1]='\0';
    printf("Dati prenume dorit: ");
    fgets(prenumE,30,stdin);
    prenumE[strlen(prenumE)-1]='\0';
    printf("Dati materia dorita: ");
    fgets(mat,30,stdin);
    mat[strlen(mat)-1]='\0';
    printf("Dati nota noua: ");
    scanf("%f",&nota_noua);
    for(i=0;i<n;i++)
        if(strcmp(numE,stud[i].nume)==0 && (strcmp(prenumE,stud[i].prenume)==0))
            for(j=0;j<m;j++)
                if(strcmp(materii[j],mat)==0)
                    stud[i].nota[j]=nota_noua;
}
