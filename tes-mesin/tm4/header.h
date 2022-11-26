/* Saya Ananda Myzza Marhelio nama 2100702 mengerjakan evaluasi TM4 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// struktur dari list
typedef struct
{
    char nama[50];
    char nim[50];
    char goldar[50];
} nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatkul kontainer;
    alamatelmt next;
    alamatelmt prev;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);
// int emptyElement(list L);
void addFirst(char nama[], char nim[], char goldar[], list *L);
void addAfter(elemen *before, char nama[], char nim[], char goldar[], list *L);
void addLast(char nama[], char nim[], char goldar[], list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void printElement(list L);
void printReverse(list L);
void delAll(list *L);
void addBefore(elemen *before, char nama[], char nim[], char goldar[], list *L);