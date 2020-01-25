#include <stdio.h>
#include <stdlib.h>

#include "alex.h"
#include "diana.h"
#include "iasmina.h"
#include "filip.h"
#include "david.h"

int main()
{

    printf("\nCum doresti sa te loghezi : Colaborator(Tasta 1)/Student(Tasta 2)/Organizator(Tasta 3)");
    int x;
    scanf("\n%d",&x);

    switch(x)
    {
        case 1: main_colaboratori();break;
        case 2: main_studenti();break;
        case 3: main_organizator();break;
        default : "Memorie insuficienta";break;
    }
    return 0;
}
