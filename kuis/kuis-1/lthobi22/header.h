/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// struktur dari list
typedef struct
{
    char jenis[50];
    char merk[50];
    char nama[50];
} dataBarang;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    dataBarang kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
// int emptyElement(list L);
void addFirst(char jenis[], char merk[], char nama[], list *L);
void addAfter(elemen *prev, char jenis[], char merk[], char nama[], list *L);
void addLast(char jenis[], char merk[], char nama[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void knockdown(list *L, list *L5);