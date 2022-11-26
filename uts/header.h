/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi UTS dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char code[20];
    char name[50];
} corp;

typedef struct
{
    char codeCorp[20];
    char zat[50];
    int month;
    int year;
} batch;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    batch kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr
{
    corp kontainer;
    eKolom *col;
    alamatebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char code[], char name[], list *L);
void addFirstK(char codeCorp[], char zat[], int month, int year, eBaris *L);
void addAfterB(eBaris *prev, char code[], char name[]);
void addAfterK(eKolom *prev, char codeCorp[], char zat[], int month, int year);
void addLastB(char code[], char name[], list *L);
void addLastK(char codeCorp[], char zat[], int month, int year, eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);

eBaris *getBaris(list L, char code[]);
eKolom *getKolom(eBaris *L, char zat[], int month, int year);
void switchKol(eBaris *temp, eKolom *tunjuk, list *L);
void swap(list *L, char zat[], int month, int year);
