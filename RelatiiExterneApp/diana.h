#ifndef DIANA_H_INCLUDED
#define DIANA_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void criptare10(char s[101]);
void decriptare10(char s[101]);
int main_colaboratori();
void Login (char username[], char parola[]);
void Creare (char username[], char parola[]);
void Examene(char colaborator[]);
void Review(char colaborator[]);
void Plata(char colaborator[]);
void Achitare(char colaborator[], char tastatura[]);
void Asteptare();

#endif // DIANA_H_INCLUDED
