/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>

/* Deklarasi Tipe Struktur untuk Stack Statis */
typedef struct
{
    char name[50];
    char expedition[50];
    char region[50];
    int weight;
} shipment;

typedef struct
{
    int top;
    shipment data[100];
} stack;

/* Prosedur dan Fungsi yang digunakan di Stack */
void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char name[], char expedition[], char region[], int weight, stack *S);
void popPush(stack *S, stack *S1);
void printStack(stack S);