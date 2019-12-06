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
