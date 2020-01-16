#include <stdio.h>

struct camera
{
    int nr_camin;
    int nr_camera;
    int nr_locuri;
    int nro_locuri;
};
void afisare_situatie(int nr_c)
{
    FILE *f = fopen("camine.int","r");
    int i,j,nr,nrc,nl,nlo;
    printf("Situatia pe camin este:\n");
    for(i=1;i<5;i++)
    {
        if(i==nr_c)
        {
            printf("Caminul numarul %d: \n",i);
            for(j=1;j<11;j++)
            {
                fscanf(f,"%d",&nr);fscanf(f,"%d",&nrc);fscanf(f,"%d",&nl);fscanf(f,"%d",&nlo);
                printf("Camera numarul %d: numarul de locuri este %d, dintre care ocupate %d.\n", nrc,nl,nlo);
            }
        }

    }
    fclose(f);
}
int schimba_camera(int nrc,int ncc,int nrd, int ncd )
{
    FILE *f = fopen("camine.int","r");
    int i,j,ok=1;
    struct camera v[5][11];
    for(i=1;i<5;i++)
        for(j=1;j<11;j++)
        {
            fscanf(f,"%d",&v[i][j].nr_camin);
            fscanf(f,"%d",&v[i][j].nr_camera);
            fscanf(f,"%d",&v[i][j].nr_locuri);
            fscanf(f,"%d",&v[i][j].nro_locuri);
        }
    fclose(f);
    FILE *ff = fopen("camine.int","w");
    if(v[nrd][ncd].nro_locuri<v[nrd][ncd].nr_locuri)
    {
        ok=0;
        v[nrc][ncc].nro_locuri--;
        v[nrd][ncd].nro_locuri++;
    }
    for(i=1;i<5;i++)
        {
            for(j=1;j<11;j++)
            fprintf(ff,"%d %d %d %d\n",i,v[i][j].nr_camera,v[i][j].nr_locuri,v[i][j].nro_locuri);
            fprintf(ff,"\n");
        }
    fclose(ff);
    return ok;
}
/* O sa incerc sa o fac dupa ce e gata logare_student
void muta_student(int nr_camin,int nr_camera,int nrd,int ncd)
{

}*/
