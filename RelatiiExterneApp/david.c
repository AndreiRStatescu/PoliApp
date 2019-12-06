#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void stele1(char s[])
{
  int i,n=strlen(s);
  for (i=0;i<n;i++)
  {
  if (s[i]==' ') s[i]='*';
    else s[i];
  }
}
void stele2(char s[])
{
  int i,n=strlen(s);
  for (i=0;i<n;i++)
  {
  if (s[i]=='*') s[i]=' ';
    else s[i];
  }
}
