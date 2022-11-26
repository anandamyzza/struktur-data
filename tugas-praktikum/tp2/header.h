/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* Deklarasi Struktur dari List Dinamis Ganda */
typedef struct
{
    char name[50];
    int date;
} bahan;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    bahan kontainer;
    alamatelmt next;
    alamatelmt prev;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

/* Prosedur dan Fungsi dalam List Dinamis Ganda */
void createList(list *L);
int countElement(list L);
void addFirst(char name[], int date, list *L);
void delFirst(list *L);

/* Prosedur untuk Ketentuan Print Data Bahan */
void printReverse(list L);
void printExpired(list L);
void printAll(list L);

/* Prosedur untuk Menghapus dan Sorting Data Bahan */
void deleteExpired(list *L);
void ascSort(list *L);
void ascSortName(list *L);