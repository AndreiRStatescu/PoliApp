#include <stdio.h>
#include <string.h>

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
int find_student(int an,char nume[30],char prenume[30],char parola[30],int nr, int nrc)
{
    FILE *f=fopen("student.int","r");
    char v[101],x[92],m='0'+an;int i,n,ok=0,t;
    x[0]=m;x[1]=',';
    t=2;n=strlen(nume)+3;
    for(i=0;i<strlen(nume)+1;i++)
    {
        if(i==strlen(nume))
        {
            x[i+t]=',';
            i++;
        }
        x[i+t]=nume[i];
    }
    t=strlen(nume)+3;
    for(i=0;i<strlen(prenume)+1;i++)
    {
        if(i==strlen(prenume))
        {
            x[i+t]=',';
            i++;
        }
        x[i+t]=prenume[i];
    }
    t=strlen(nume)+4+strlen(prenume);
    for(i=0;i<strlen(parola);i++)
        x[i+t]=parola[i];
    t=strlen(nume)+strlen(prenume)+strlen(parola)+4;
    x[t]=',';x[t+1]='0'+nr;x[t+2]=',';x[t+3]='0'+nrc;x[t+4]='\0';
    while(fgets(v,97,f)!=NULL)
    {
        i=0;
        while((i<strlen(x))&&(ok==0))
        {
            if(v[i]!=x[i])
                ok=1;
            i++;//printf("%d %d \n",i,strlen(x));
        }
        if(i==strlen(x))
        {
            ok=1;
            break;
        }
        ok=0;
    }
    fclose(f);
    return ok;
}
void cerere_transfer(){
    char nume[30],prenume[30],parola[30];
    int an,nr,nc,nrd,ncd,k;
    FILE *f=fopen("cerere.int","a");
    printf("Completeaza urmatorul fomular: \n");
    printf("Subsemnatul (1) (2) ,din anul (3), acutualmente locuind in caminul (4) camera (5) doreste sa depuna o cerere de transfer pentru a se muta in caminul (6) , camera (7) \n");
    printf("(1) Numele:");getchar();fgets(nume,30,stdin);
    printf("(2) Prenume:");fgets(prenume,30,stdin);
    printf("(3) An:");scanf("%d",&an);
    printf("(4) Caminul in care locuiesti:");scanf("%d",&nr);
    printf("(5) Camera in care locuiesti:");scanf("%d",&nc);
    printf("(6) Caminul in care doresti sa te muti:");scanf("%d",&nrd);
    printf("(7) Camera in care doresti sa te muti:");scanf("%d",&ncd);
    printf("Pentru a confirma te rugam reintrodu parola:");getchar();fgets(parola,30,stdin);
    nume[strlen(nume)-1]='\0';
    prenume[strlen(prenume)-1]='\0';
    parola[strlen(parola)-1]='\0';
    k=find_student(an,nume,prenume,parola,nr,nc);
    if(k==1)
    {
        fprintf(f,"%d,%s,%s,%s,%d,%d,%d,%d \n",an,nume,prenume,parola,nr,nc,nrd,ncd);
        printf("Cererea a fost inregistrata cu succes, un admin o sa iti evalueze cererea in cel mai scurt timp.");
    }
    else
        printf("Datele introduse sunt gresite!\n");
    fclose(f);
}


