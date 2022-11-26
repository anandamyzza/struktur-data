/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM3 dalam mata kuliah Struktur Datas
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>

// struktur dari list
typedef struct
{
    char nama[50];
    char tanggal[50];
    int jumlah;
} nilaiMatkul;

typedef struct
{
    nilaiMatkul kontainer;
    int next;
    int prev;
} elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char tanggal[], int jumlah, list *L);
void addAfter(int prev, char nama[], char tanggal[], int jumlah, list *L);
void addLast(char nama[], char tanggal[], int jumlah, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void printReverse(list L);