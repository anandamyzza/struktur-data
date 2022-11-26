/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* Deklarasi Tipe Struktur untuk Queue Dinamis */
typedef struct
{
    char name[50];
    char job[50];
    int order;
} freelancer;

typedef struct elm *alamatelmt;
typedef struct elm
{
    freelancer kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *last;
} queue;

/* Prosedur dan Fungsi yang digunakan di Queue */
void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char name[], char job[50], int order, queue *Q);
void addPriority(char name[], char job[50], int order, int priority, queue *Q);
void move(queue *Q1, queue *Q2);
void printQueue(queue Q, int num);