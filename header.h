/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* Deklarasi Struktur dari List */
typedef struct
{
    char title[150];
    char tv[150];
    double rating;
} dataTayangan;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    dataTayangan kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

/* Prosedur dan Fungsi dalam List Tunggal Dinamis */
void createList(list *L);
int countElement(list L);
void addFirst(char title[], char tv[], double rating, list *L);
void addAfter(elemen *prev, char title[], char tv[], double rating, list *L);
void addLast(char title[], char tv[], double rating, list *L);
void delFirst(list *L);
void delAfter(elemen *prev);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);

/* Prosedur untuk Sorting Ascending/Descending Data dalam Program */
void bubbleDescRate(list *L);
void bubbleAscRate(list *L);
void bubbleDescTitle(list *L);
void bubbleAscTitle(list *L);