#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void criptare (char s[101])
{
    int i;
    for(i=0;i<strlen(s);i++)
    {
        if(i%2==0)
            s[i]=s[i]+3;
        else
            s[i]=s[i]-1;

    }
    //strrev(s);
}
void decriptare (char s[101])
{
    //strrev(s);

    int i;
    for(i=0;i<strlen(s);i++)
    {
        if(i%2==0)
            s[i]=s[i]-3;
        else
            s[i]=s[i]+1;

    }


}
int cautare()
{
    char *numeuser,*parolauser;
    numeuser=(char*)malloc(20*sizeof(char));
    parolauser=(char*)malloc(20*sizeof(char));

    printf("Introduceti numele de user:");
    fgets(numeuser,20,stdin);
    numeuser[strlen(numeuser)-1]='\0';
    printf("Introduceti parola:");
    fgets(parolauser,20,stdin);
    parolauser[strlen(parolauser)-1]='\0';

    char linii[200];
    FILE* fis;
    fis=fopen("practicaa.int","r");
    int i,j;
    while(fgets(linii,200,fis))
    {
        char *a,*b;
        a=(char*)malloc(20*sizeof(char));
        b=(char*)malloc(20*sizeof(char));
        int vf=1;
        int k=0;
        for(i=0;linii[i]!=',';i++)
        {
            a[k]=linii[i];
            k++;
        }

        a[k]='\0';
        j=k+1;

        if(strlen(a)!=strlen(numeuser))
            vf=0;
        else
        {
          for(i=0;i<strlen(numeuser);i++)
            if(numeuser[i]!=a[i])
            vf=0;
        }
        k=0;
        for(i=j;linii[i]!=',';i++)
        {
            b[k]=linii[i];
            k++;
        }
        b[k]='\0';

        if(strlen(b)!=strlen(parolauser))
            vf=0;
        else
        {
          for(i=0;i<strlen(parolauser);i++)
            if(parolauser[i]!=b[i])
            vf=0;
        }
        if(vf==1)
        {   fclose(fis);
            return 1;

        }





    }
    fclose(fis);
    return 0;

}


