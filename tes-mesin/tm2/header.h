/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// struktur dari list
typedef struct
{
    char nama[50];
    char jenis_kelamin[10];
    char buku[50];
} nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    nilaiMatkul kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
// int emptyElement(list L);
void addFirst(char nim[], char nama[], char nilai[], list *L);
void addAfter(elemen *prev, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);