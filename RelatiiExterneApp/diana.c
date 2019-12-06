#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void criptare10(char s[101])
{
    int i;
    int n=strlen(s);
    char aux;
    for(i=0;i<n/2;i++)
    {
        aux=s[i];
        s[i]=s[n-i-1];
        s[n -i-1]=aux;
    }

}
void decriptare10(char s[101])
{
    criptare10(s);
}
