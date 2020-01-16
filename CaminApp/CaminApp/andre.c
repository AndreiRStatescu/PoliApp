#include <stdio.h>
int cauta_student()
{
    char *nume,*prenume,*parola;


    nume=malloc(100*sizeof(char));
    prenume=malloc(100*sizeof(char));
    parola=malloc(100*sizeof(char));

    printf("Numele:");
    fgets(nume,100,stdin);
    nume[strlen(nume)-1]='\0';
    printf("Prenumele:");
    fgets(prenume,100,stdin);
    prenume[strlen(prenume)-1]='\0';
    printf("Parola:");
    fgets(parola,100,stdin);
    parola[strlen(parola)-1]='\0';

    int j,i,r,q=0,k;

    char line[300];

    FILE* fp;
    fp = fopen("student.int", "r");

    while (fgets(line,300, fp))
    {
        char *x=NULL,*y=NULL,*z=NULL;
        x=malloc(100*sizeof(char));
        y=malloc(100*sizeof(char));
        z=malloc(100*sizeof(char));
        r=1;
        j=0;

        do
        {
            j++;
        }
        while(line[j]!=',');

        j++;
        k=-1;
        for(i=j; line[i]!=','; i++)
            x[++k]=line[i];

        x[k+1]='\0';
        j=i+1;
        if(strlen(x)!=strlen(nume))
            r=0;
        else
            for(i=0; nume[i]!='\0'; i++)
                if(nume[i]!=x[i])
                    r=0;
        k=-1;
        for(i=j; line[i]!=','; i++)
        {
            y[++k]=line[i];
        }
        j=i+1;
        y[k+1]='\0';

        if(strlen(y)!=strlen(prenume))
            r=0;
        else
            for(i=0; prenume[i]!='\0'; i++)
                if(prenume[i]!=y[i])
                    r=0;
        k=-1;
        for(i=j; line[i]!=','; i++)
            z[++k]=line[i];
        z[k+1]='\0';
        if(strlen(z)!=strlen(parola))
            r=0;
        else
            for(i=0; parola[i]!='\0'; i++)
                if(parola[i]!=z[i])
                    r=0;
        if(r==1)
        {
            q++;
            fclose(fp);
            return q;
        }
        else
            q++;




    }
    return 0;

}

int cauta_admin()
{
    char *nume,*camin,*parola;
    nume=malloc(100*sizeof(char));
    camin=malloc(100*sizeof(char));
    parola=malloc(100*sizeof(char));
    printf("Caminul:");
    fgets(camin,100,stdin);
    camin[strlen(camin)-1]='\0';
    printf("Numele:");
    fgets(nume,100,stdin);
    nume[strlen(nume)-1]='\0';
    printf("Parola:");
    fgets(parola,100,stdin);
    parola[strlen(parola)-1]='\0';
    int j,i,q=0;
    char line[300];

    FILE* fp;
    fp = fopen("admin.int", "r");

    while (fgets(line,300, fp))
    {
        int r=1;
        char *x=NULL,*y=NULL,*w=NULL;
        x=malloc(100*sizeof(char));
        y=malloc(100*sizeof(char));
        w=malloc(100*sizeof(char));
        for(i=0; line[i]!=','; i++)
            x[i]=line[i];
        x[i]='\0';

        if(strlen(camin)!=strlen(x))
            r=0;
        else
            for(i=0; camin[i]!='\0'; i++)
                if(camin[i]!=x[i])
                    r=0;
        j=i+1;
        int k=-1;
        for(i=j; line[i]!=','; i++)
        {
            y[++k]=line[i];

        }
        y[k+1]='\0';
        j=i+1;
        if(strlen(nume)!=strlen(y))
            r=0;
        else
            for(i=0; nume[i]!='\0'; i++)
                if(nume[i]!=y[i])
                    r=0;

        k=-1;
        for(i=j; i<strlen(line); i++)
            w[++k]=line[i];
        w[k]='\0';
        if(strlen(parola)!=strlen(w))
            r=0;
        else
            for(i=0; parola[i]!='\0'; i++)
                if(parola[i]!=w[i])
                    r=0;
        if(r==1)
        {
            fclose(fp);
            return camin;
        }
        else
            q++;




    }
    return 0;
}
