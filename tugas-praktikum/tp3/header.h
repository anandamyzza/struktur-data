/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP3 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* Deklarasi Tipe Struktur untuk Stack Dinamis */
typedef struct
{
    int year;
    char name[50];
    char band[50];
} music;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    music kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

/* Prosedur dan Fungsi yang digunakan di Stack */
void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(int year, char name[], char band[], stack *S);
void pop(stack *S);
void move(stack *Sa, stack *Sb);
void printStack(stack S, int status);