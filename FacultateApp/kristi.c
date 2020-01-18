#include<stdio.h>
#include<string.h>
struct student
{
    char nume[31], prenume[31], sectie[11];
    int an;
    float taxa, nota;
};
void eliminare(struct student v[], char nume[] , char prenume[],int nrStd)
{
    int i,k,j ,x;
    for(i=0;i<nrStd;i++)
    {
        if(strcmp(v[i].nume,nume)==0 && strcmp(v[i].prenume,prenume)==0)
        {
            k=i;
            break;
        }
    }
    for(j=k;j<nrStd;j++)
    {
        strcpy(v[j].nume,v[j+1].nume);
    }
    for(x=k;x<nrStd;x++)
        strcpy(v[x].prenume,v[x+1].prenume);

}


void transfer(struct student students[], int nrStd , char nume[],char prenume[],char sectienoua[])
{
    int i,k;
    for(i=0;i<nrStd;i++)
    {
        if(strcmp(students[i].nume,nume)==0 && strcmp(students[i].prenume,prenume)==0)
        {
             strcpy(students[i].sectie,sectienoua);
        }
    }
}
