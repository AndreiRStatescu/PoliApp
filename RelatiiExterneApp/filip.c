#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void done(char sir[])
{
    int i;
    for(i=0;i<=strlen(sir);i++)
        if (sir[i]=='a'||sir[i]=='e'||sir[i]=='o'||sir[i]=='u'||sir[i]=='i')
        sir[i]=sir[i]-'a'+'A';
}
void undone(char sir[])
{
    int i;
    for(i=0;i<=strlen(sir);i++)
        if(sir[i]=='A'||sir[i]=='E'||sir[i]=='O'||sir[i]=='U'||sir[i]=='I')
        sir[i]=sir[i]-'A'+'a';
}
