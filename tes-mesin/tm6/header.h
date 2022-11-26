/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM6 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char name[50];
    int price;
} nilaiMatKul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatKul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char name[], int price, stack *S);
void pop(stack *S);
void move(stack *Sa, stack *Sb);
void printStack(stack S);