/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM7 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char name[50];
    int rate;
} nilaiMatKul;

typedef struct elm *alamatelmt;
typedef struct elm
{
    nilaiMatKul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char name[], int rate, queue *Q);
void addPriority(char name[], int rate, int priority, queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, int num);